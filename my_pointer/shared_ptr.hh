#pragma once

#include <cstddef>

#include "unique_ptr.hh"

template <typename T>
class shared_ptr
{
private:
  struct controll_block
  {
    unique_ptr<T> data;
    std::size_t pointers;
  };

  controll_block *block;

public:
  shared_ptr();
  shared_ptr(T *ptr);
  shared_ptr(shared_ptr &&other);
  shared_ptr(const shared_ptr &other);

  ~shared_ptr();

  shared_ptr &operator=(const shared_ptr &other);
  shared_ptr &operator=(shared_ptr &&other);

  T &operator*();
  T *operator->();

  explicit operator bool();
};

#include "shared_ptr.tcc"