#pragma once

#include <cstddef>
#include <queue>
#include <vector>

template <typename T> class CompleteBinaryTree
{

public:
  typedef T                                 value_type;
  typedef std::size_t                       size_type;
  typedef T                                &reference;
  typedef const T                          &const_reference;
  typedef typename std::vector<T>::iterator Position;

  CompleteBinaryTree()
    : _v(1)
  {
  }

  Position left(const Position &p) const { return pos(idx(p) * 2); }
  Position right(const Position &p) const { return pos(idx(p) * 2 + 1); }
  Position parent(const Position &p) const { return pos(idx(p) / 2); }

  Position root() { return pos(1); }
  Position last() { return pos(size()); }

  void add_last(const_reference e) { _v.push_back(e); }
  void remove_last() { _v.pop_back(); }
  void swap(const Position &p, const Position &q) { std::swap(*p, *q); }

  bool has_left(const Position &p) const { return (idx(p) * 2 < _v.size()); }
  bool has_right(const Position &p) const
  {
    return (idx(p) * 2 + 1 < _v.size());
  }
  bool is_root(const Position &p) const { return idx(p) == 1; }

  size_type size() const { return _v.size() - 1; }

protected:
  Position pos(size_type i) { return _v.begin() + i; }

  size_type idx(const Position &p) { return p - _v.begin(); }

private:
  std::vector<value_type> _v;
};