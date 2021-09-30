#include "linked_list.hh"

template <class T>
void linked_list<T>::push_back(T element)
{
  node *new_node = new node();
  new_node->data = element;

  if (tail)
  {
    tail->next = new_node;
    new_node->prev = tail;
  }
  if (!head)
  {
    head = new_node;
  }
  tail = new_node;
}

template <class T>
void linked_list<T>::erase(const node *node)
{
  if (node->prev)
  {
    node->prev->next = node->next;
  }
  if (node->next)
  {
    node->next->prev = node->prev;
  }

  if (node == head)
  {
    head = node->next;
  }
  if (node == tail)
  {
    tail = node->prev;
  }

  delete node;
}

template <class T>
const typename linked_list<T>::node *linked_list<T>::begin() const
{
  return head;
}