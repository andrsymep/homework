#pragma once

#include "linked_list.hh"
#include "failure.hh"

class database
{
private:
  linked_list<failure> failures;

public:
  void add_failure(failure failure);
  void delete_failure(int id);
  const linked_list<failure> &get_failures();
};