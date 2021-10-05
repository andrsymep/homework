#include <utility>
#include <stdexcept>
#include <algorithm>
#include <string>

#include "vector.hh"

using std::size_t;
using std::to_string;

template <typename T>
vector<T>::vector()
{
  _size = 0;
  _capacity = 0;
  _data = nullptr;
}

template <typename T>
vector<T>::vector(const std::size_t size, const T &default_value) : vector()
{
  resize(size, default_value);
}

template <typename T>
vector<T>::vector(const vector &other) : vector()
{
  &this = other;
}

template <typename T>
void vector<T>::push_back(const T &element)
{
  ensure_capacity();

  _data[_size] = element;
  _size++;
}

template <typename T>
void vector<T>::push_back(T &&element)
{
  ensure_capacity();

  _data[_size] = std::move(element);
  _size++;
}

template <typename T>
void vector<T>::pop_back()
{
  if (_size == 0)
  {
    throw std::logic_error("Attempt to delete an element in empty vector.");
  }

  _size--;
}

template <typename T>
const T &vector<T>::operator[](const size_t index) const
{
  if (index >= _size)
  {
    throw std::out_of_range("Attempt to access element at index " + to_string(index) + " in a vector with size " + to_string(_size) + ".");
  }

  return _data[index];
}

template <typename T>
T &vector<T>::operator[](const size_t index)
{
  if (index >= _size)
  {
    throw std::out_of_range("Attempt to access element at index " + to_string(index) + " in a vector with size " + to_string(_size) + ".");
  }

  return _data[index];
}

template <typename T>
void vector<T>::clear()
{
  delete[] _data;
  _data = nullptr;
  _size = 0;
  _capacity = 0;
}

template <typename T>
size_t vector<T>::size() const
{
  return _size;
}

template <typename T>
size_t vector<T>::capacity() const
{
  return _capacity;
}

template <typename T>
bool vector<T>::empty() const
{
  return _size == 0;
}

template <typename T>
const T *vector<T>::data() const
{
  return _data;
}

template <typename T>
void vector<T>::ensure_capacity()
{
  if (_capacity > _size)
  {
    return;
  }

  reserve(std::max<size_t>(_size * 2, 1));
}

template <typename T>
void vector<T>::reserve(const size_t capacity) const
{
  if (_capacity >= capacity)
  {
    return;
  }

  T *new_data = new T[capacity];
  std::copy(_data, _data + _size, new_data);
  delete[] _data;
  _data = new_data;
  _capacity = capacity;
}

template <typename T>
void vector<T>::resize(const size_t size, const T &value)
{
  if (_size == size)
  {
    return;
  }

  reserve(size);

  if (_size < size)
  {
    std::fill(_data + _size, _data + size, value);
  }

  _size = size;
}

template <typename T>
vector<T>::~vector()
{
  clear();
}

template <typename T>
vector<T> &vector<T>::operator=(const vector &other)
{
  reserve(other._size);
  std::copy(other._data, other._data + other._size, _data);
  _size = other._size;

  return *this;
}

template <typename T>
vector<T> &vector<T>::operator=(vector &&other)
{
  _data = other._data;
  _size = other._size;
  _capacity = other._capacity;

  other._data = nullptr;
  other.clear();

  return *this;
}
