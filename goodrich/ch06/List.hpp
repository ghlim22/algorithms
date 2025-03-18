#pragma once

#include <cstddef>

template <typename T> class List
{
public:
  // member types
  typedef T           value_type;
  typedef std::size_t size_type;
  typedef T          &reference;
  typedef const T    &const_reference;

private:
  struct Node {
    value_type e;
    Node      *prev;
    Node      *next;
  };

public:
  class Iterator
  {
  public:
    value_type &operator*() { return _n->e; }

    bool operator==(const Iterator &other) const { return _n == other._n; }

    bool operator!=(const Iterator &other) const { return !operator==(other); }

    Iterator &operator++()
    {
      _n = _n->next;
      return *this;
    }

    Iterator &operator--()
    {
      _n = _n->prev;
      return *this;
    }

    friend class List<T>;

  private:
    Iterator(Node *n)
      : _n(n)
    {
    }

    Node *_n;
  };

public:
  List()
    : _header(new Node)
    , _trailer(new Node)
    , _size(0)
  {
    _header->prev  = NULL;
    _header->next  = _trailer;
    _trailer->prev = _header;
    _trailer->next = NULL;
  }

  ~List()
  {
    while (!empty()) {
      pop_front();
    }
    delete _header;
    delete _trailer;
  }

  // Capacity

  size_type size() const { return _size; }

  bool empty() const { return _size == 0; }

  // Iterators [begin, end)

  Iterator begin() const { return Iterator(_header->next); }

  Iterator end() const { return Iterator(_trailer); }

  // Modifiers

  void push_front(const_reference e)
  {
    // Node *new_node      = new Node;
    // new_node->e         = e;
    // new_node->prev      = _header;
    // new_node->next      = _header->next;
    // _header->next->prev = new_node;
    // _header->next       = new_node;
    insert(begin(), e);
  }

  void push_back(const_reference e)
  {
    // Node *new_node       = new Node;
    // new_node->e          = e;
    // new_node->prev       = _trailer->prev;
    // new_node->next       = _trailer;
    // _trailer->prev->next = new_node;
    // _trailer->prev       = new_node;
    insert(end(), e);
  }

  // insert e before it
  void insert(const Iterator &it, const_reference e)
  {
    Node *n        = it._n;
    Node *new_node = new Node;
    new_node->e    = e;
    new_node->prev = n->prev;
    new_node->next = n;
    n->prev->next  = new_node;
    n->prev        = new_node;
    ++_size;
  }

  void pop_front() { erase(begin()); }

  void pop_back() { erase(--end()); }

  void erase(const Iterator &it)
  {
    Node *n       = it._n;
    n->prev->next = n->next;
    n->next->prev = n->prev;
    delete n;
    --_size;
  }

private:
  Node     *_header;
  Node     *_trailer;
  size_type _size;
};