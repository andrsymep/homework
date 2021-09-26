#pragma once

#include <iostream>

#include "column.hh"

class table
{
public:
  std::vector<column> columns;
  friend std::ostream &operator<<(std::ostream &os, const table &table);
};