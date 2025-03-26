#pragma once

#include "CompleteBinaryTree.hpp"
#include <cstdlib>

/* Min-heap */
template <typename T, typename Compare> class PriorityQueue
{
public:
  // member types
  typedef T                                        value_type;
  typedef std::size_t                              size_type;
  typedef T                                       &reference;
  typedef const T                                 &const_reference;
  typedef typename CompleteBinaryTree<T>::position position;

  size_type size() const { return _c.size(); }

  bool empty() const { return _c.empty(); }

  void push(const_reference e)
  {
    _c.add_last(e);
    position v = _c.last();
    while (!_c.is_root(v)) {
      position w = _c.parent(v);
      if (!_less(*v, *w)) {
        break;
      }
      _c.swap(v, w);
      v = w;
    }
  }

  void pop()
  {
    if (_c.size() == 1) {
      _c.remove_last();
      return;
    }

    position v = _c.root();
    _c.swap(v, _c.last());
    _c.remove_last();

    while (_c.has_left(v)) {
      position child = _c.left(v);

      if (_c.has_right(v)) {
        position right = _c.right(v);
        if (_less(*right, *child)) {
          child = right;
        }
      }

      if (_less(*child, *v)) {
        _c.swap(child, v);
        v = child;
      } else {
        break;
      }
    }
  }

  const_reference top() { return *_c.root(); }

private:
  CompleteBinaryTree<T> _c;
  Compare               _less;
};

template <typename T> class Less
{
public:
  bool operator()(const T &a, const T &b) { return (a < b); }
};