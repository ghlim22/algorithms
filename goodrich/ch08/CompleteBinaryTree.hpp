#pragma once

#include <cstddef>
#include <utility>
#include <vector>

template <typename T> class CompleteBinaryTree
{
public:
  // member types
  typedef T                                 value_type;
  typedef std::size_t                       size_type;
  typedef T                                &reference;
  typedef const T                          &const_reference;
  typedef typename std::vector<T>::iterator position;

  CompleteBinaryTree()
    : _v(1)
  {
  }

  position left(const position &p) { return (pos(idx(p) * 2)); }

  position right(const position &p) { return (pos(idx(p) * 2) + 1); }

  position parent(const position &p) { return (pos(idx(p) / 2)); }

  bool has_left(const position &p) const { return (idx(p) * 2 < _v.size()); }

  bool has_right(const position &p) const
  {
    return ((idx(p) * 2 + 1) < _v.size());
  }

  bool is_root(const position &p) const { return (idx(p) == 1); }

  position root() { return pos(1); }

  position last() { return pos(_v.size() - 1); }

  void add_last(const_reference e) { _v.push_back(e); }

  void remove_last() { _v.pop_back(); }

  void swap(const position &p, const position &q)
  {
    value_type t;
    t  = *p;
    *p = *q;
    *q = t;
  }

  // capaticy
  size_type size() const { return (_v.size() - 1); }

  bool empty() const { return size() == 0; }

protected:
  position  pos(int i) { return (_v.begin() + i); }
  size_type idx(const position &pos) const { return (pos - _v.begin()); }

private:
  std::vector<T> _v;
};