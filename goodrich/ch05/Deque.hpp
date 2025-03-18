#pragma once

#include "DoublyLinkedList.hpp"
#include <cstddef>

template <typename T> class Deque
{
public:
  Deque();
  Deque(const Deque<T> &other);
  Deque<T> &operator=(const Deque<T> &other);
  ~Deque();
  void     push_front(const T &e);
  void     push_back(const T &e);
  void     pop_front();
  void     pop_back();
  T       &front();
  const T &front() const;
  T       &back();
  const T &back() const;
  size_t   size() const;
  bool     empty() const;

private:
  DLinkedList<T> _container;
  size_t         _size;
};

template <typename T>
Deque<T>::Deque()
  : _container()
  , _size()
{
}

template <typename T>
Deque<T>::Deque(const Deque<T> &other)
  : _container(other._container)
  , _size(other._size)
{
}

template <typename T> Deque<T> &Deque<T>::operator=(const Deque<T> &other)
{
  if (this == &other) {
    return *this;
  }

  _container = other._container;
  _size      = other._size;
}

template <typename T> Deque<T>::~Deque() {}

template <typename T> void Deque<T>::push_front(const T &e)
{
  _container.push_front(e);
  ++_size;
}

template <typename T> void Deque<T>::push_back(const T &e)
{
  _container.push_back(e);
  ++_size;
}

template <typename T> void Deque<T>::pop_front()
{
  _container.pop_front();
  --_size;
}

template <typename T> void Deque<T>::pop_back()
{
  _container.pop_back();
  --_size;
}

template <typename T> T &Deque<T>::front() { return _container.front(); }

template <typename T> const T &Deque<T>::front() const
{
  return _container.front();
}

template <typename T> T &Deque<T>::back() { return _container.back(); }

template <typename T> const T &Deque<T>::back() const
{
  return _container.back();
}

template <typename T> size_t Deque<T>::size() const { return _size; }

template <typename T> bool Deque<T>::empty() const
{
  return _container.empty();
}