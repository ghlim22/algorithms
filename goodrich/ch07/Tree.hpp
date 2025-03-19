#pragma once

#include <cstddef>
#include <list>

template <typename T> class Tree
{
public:
  // member types
  typedef T           value_type;
  typedef std::size_t size_type;
  typedef T          &reference;
  typedef const T    &const_reference;

  class Position
  {
  public:
  reference operator*();
  Position parent() const;
  std::list<Position> children() const;
  bool is_root() const;
  bool is_external() const;
  };

  size_type size() const;
  bool empty() const;
  Position root() const;
  std::list<Position> positions() const;

private:
};