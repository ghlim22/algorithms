#pragma once

#include <cstddef>
#include <cstdlib>
#include <cstring>
#include <stdexcept>

template <typename T> class Vector
{
public:
  // member types
  typedef T           value_type;
  typedef std::size_t size_type;
  typedef T          &reference;
  typedef const T    &const_reference;

  // member functions
  Vector<T>(size_type n = 32)
    : _capacity(n)
    , _size(0)
    , _c(new value_type[n])
  {
  }

  Vector<T>(const Vector<T> &other)
    : _capacity(other._capacity)
    , _size(other._size)
    , _c(new value_type[other._capacity])
  {
    // copy
  }

  Vector<T> &operator=(const Vector<T> &other)
  {
    if (this == &other) {
      return *this;
    }

    delete[] _c;
    _capacity = other._capacity;
    _size     = other._size;
    _c = new value_type[_capacity];
    // copy
  }

  ~Vector<T>() {delete[] _c; }

  // element access
  reference at(size_type pos)
  {
    if (pos < 0 || pos >= _size) {
      throw std::out_of_range("out of range");
    }
    return _c[pos];
  }

  const_reference at(size_type pos) const
  {
    if (pos < 0 || pos >= _size) {
      throw std::out_of_range("out of range");
    }
    return _c[pos];
  }

  reference operator[](size_type pos) { return _c[pos]; }

  const_reference operator[](size_type pos) const { return _c[pos]; }

  reference front() { return _c[0]; }

  const_reference front() const { return _c[0]; }

  reference back() { return _c[_size - 1]; }

  const_reference back() const { return _c[_size - 1]; }

  // capacity
  bool empty() const { return _size == 0; }

  size_type size() const { return _size; }

  void reserve(size_type new_cap)
  {
    if (new_cap <= _capacity) {
      return;
    }

    value_type *new_c = new value_type[new_cap];
    std::memmove(new_c, _c, sizeof(value_type) * _size);
    delete[] _c;
    _c        = new_c;
    _capacity = new_cap;
  }

  size_type capacity() const { return _capacity; }

  // modifiers
  void erase(size_type idx)
  {
    for (int i = idx + 1; i < _size; ++i) {
      _c[i - 1] = _c[i];
    }
    --_size;
  }

  void insert(size_type idx, const_reference e)
  {
    if (_size == _capacity) {
      reserve(_capacity * 2);
    }
    for (int i = _size; i > idx; --i) {
      _c[i] = _c[i - 1];
    }
    _c[idx] = e;
    ++_size;
  }

  void push_back(const_reference e) {
    insert(_size, e);
  }

  void pop_back() {
    erase(_size - 1);
  }

private:
  size_type   _capacity;
  size_type   _size;
  value_type *_c;
};