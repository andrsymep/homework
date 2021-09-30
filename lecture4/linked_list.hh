#pragma once

#include <memory>

template <class T>
class linked_list
{
public:
  struct node
  {
    T data;
    node *next = nullptr, *prev = nullptr;
  };

  const node *begin() const;

  void push_back(T element);
  void erase(const node *node);

private:
  node *head = nullptr, *tail = nullptr;
};

#include "linked_list.tcc"