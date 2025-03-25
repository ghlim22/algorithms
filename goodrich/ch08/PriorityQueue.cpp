#pragma once

#include <cstddef>

template<typename T, typename Compare>
class PriorityQueue {
public:
  // member types
  typedef T           value_type;
  typedef std::size_t size_type;
  typedef T          &reference;
  typedef const T    &const_reference;

  size_type size() const;
  


};