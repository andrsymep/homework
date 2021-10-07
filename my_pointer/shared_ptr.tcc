#include <utility>

#include "shared_ptr.hh"

template <typename T>
shared_ptr<T>::shared_ptr() : shared_ptr(nullptr) {}

template <typename T>
shared_ptr<T>::shared_ptr(T *ptr)
{
  block = new controll_block{
      .data = ptr,
      .pointers = 1};
}

template <typename T>
shared_ptr<T>::shared_ptr(const shared_ptr &other) : shared_ptr(nullptr)
{
  *this = other;
}

template <typename T>
shared_ptr<T>::shared_ptr(shared_ptr &&other)
{
  *this = std::move(other);
}

template <typename T>
shared_ptr<T>::~shared_ptr()
{
  if (block)
  {
    block->pointers--;
    if (block->pointers == 0)
    {
      delete block;
    }
  }
}

template <typename T>
shared_ptr<T> &shared_ptr<T>::operator=(const shared_ptr &other)
{
  this->~shared_ptr();

  block = other.block;
  block->pointers++;

  return *this;
}

template <typename T>
shared_ptr<T> &shared_ptr<T>::operator=(shared_ptr &&other)
{
  block = other.block;
  other.block = nullptr;
  return *this;
}

template <typename T>
T &shared_ptr<T>::operator*()
{
  return *(block->data);
}

template <typename T>
T *shared_ptr<T>::operator->()
{
  return block->data.get();
}

template <typename T>
shared_ptr<T>::operator bool()
{
  return (*block->data) != nullptr;
}