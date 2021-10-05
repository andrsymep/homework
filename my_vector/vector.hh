#pragma once

#include <cstddef>

template <typename T>
class vector
{
private:
  mutable T *_data;
  mutable std::size_t _capacity;

  std::size_t _size;

  void ensure_capacity();

public:
  vector();
  vector(const std::size_t size, const T &value = T());
  vector(const vector &other);

  vector &operator=(const vector &other);
  vector &operator=(vector &&other);

  void push_back(const T &element);
  void push_back(T &&element);

  void pop_back();

  const T &operator[](const std::size_t index) const;
  T &operator[](const std::size_t index);

  void reserve(const std::size_t capacity) const;
  void resize(const std::size_t size, const T &value = T());

  void clear();

  std::size_t size() const;
  std::size_t capacity() const;
  bool empty() const;

  const T *data() const;

  ~vector();
};

#include "vector.tcc"