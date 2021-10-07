#pragma once

template <typename T>
class unique_ptr
{
private:
  T *data;

public:
  unique_ptr();
  unique_ptr(T *ptr);
  unique_ptr(unique_ptr &&other);
  unique_ptr(const unique_ptr &other) = delete;

  ~unique_ptr();

  unique_ptr &operator=(const unique_ptr &other) = delete;
  unique_ptr &operator=(unique_ptr &&other);

  T &operator*();
  T *operator->();

  T *get();
};

#include "unique_ptr.tcc"