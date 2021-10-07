#include <utility>

#include "unique_ptr.hh"

template <typename T>
unique_ptr<T>::unique_ptr()
{
  data = nullptr;
}

template <typename T>
unique_ptr<T>::unique_ptr(T *ptr)
{
  data = ptr;
}

template <typename T>
unique_ptr<T>::unique_ptr(unique_ptr &&other)
{
  *this = std::move(other);
}

template <typename T>
unique_ptr<T>::~unique_ptr()
{
  delete data;
}

template <typename T>
unique_ptr<T> &unique_ptr<T>::operator=(unique_ptr &&other)
{
  data = other.data;
  other.data = nullptr;
  return *this;
}

template <typename T>
T &unique_ptr<T>::operator*()
{
  return *data;
}

template <typename T>
T *unique_ptr<T>::operator->()
{
  return data;
}

template <typename T>
T *unique_ptr<T>::get()
{
  return data;
}