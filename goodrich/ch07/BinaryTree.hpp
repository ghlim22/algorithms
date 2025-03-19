#pragma once

#include <cstddef>
#include <list>

// An incomplete interface of proper binary tree
template <typename T> class BinaryTree
{
public:
  // member types
  typedef T           value_type;
  typedef std::size_t size_type;
  typedef T          &reference;
  typedef const T    &const_reference;

protected:
  struct Node {
    value_type val;
    Node      *left;
    Node      *right;
    Node      *parent;
    Node()
      : val()
      , left(NULL)
      , right(NULL)
      , parent(NULL)
    {
    }
  };

public:
  class Position
  {
  public:
    Position(Node *n = NULL)
      : _v(n)
    {
    }

    reference operator*() { return _v->val; };

    Position left() const { return Position(_v->left); }

    Position right() const { return Position(_v->right); }

    Position parent() const { return Position(_v->parent); }

    bool is_root() const { return _v->parent == NULL; }

    bool is_external() const { return _v->left == NULL && _v->right == NULL; }

    friend class BinaryTree<T>;

  private:
    Node *_v;
  };

  typedef std::list<Position> PositionList;

  BinaryTree()
    : _root(NULL)
    , _size(0)
  {
  }

  ~BinaryTree() { clear(_root); }

  void clear(Node *p)
  {
    if (p == NULL)
      return;
    if (p->left)
      clear(p->left);
    if (p->right)
      clear(p->right);
    delete p;
  }

  size_type size() const { return _size; }

  bool empty() const { return _size == 0; }

  Position root() const { return Position(_root); }

  PositionList positions()
  {
    PositionList ret;
    preorder(_root, ret);
    return ret;
  } // get list of all nodes in the tree

  void add_root() // add root to empty tree
  {
    _root = new Node;
    _size = 1;
  }

  void expand_external(const Position &p) // expand a external node
  {
    p._v->left          = new Node;
    p._v->right         = new Node;
    p._v->left->parent  = p._v;
    p._v->right->parent = p._v;
    _size += 2;
  }

  Position remove_above_external(const Position &p) // remove p and its parent
  {
    // let w be p's associated node and let v be its parent
    // we assume that w is external and is not the root
    Node *w   = p._v;
    Node *v   = w->parent;
    Node *sib = ((w == v->left) ? v->right : v->left);
    if (v == _root) {
      _root         = sib;
      _root->parent = NULL;
    } else {
      Node *gpar = v->parent;
      if (gpar->left == v)
        gpar->left = sib;
      else
        gpar->right = sib;
      sib->par = gpar;
    }
    delete w;
    delete v;
    _size -= 2;
    return Position(sib);
  }

protected:
  void preorder(Node *v, PositionList &l) const // preorder utility
  {
    if (v == NULL)
      return;
    l.push_back(Position(v));
    if (v->left != NULL)
      preorder(v->left, l);
    if (v->right != NULL)
      preorder(v->right, l);
  }

private:
  Node     *_root;
  size_type _size;
};