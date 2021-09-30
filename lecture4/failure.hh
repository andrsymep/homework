#pragma once

#include <string>
#include <vector>

struct failure
{
  int id;
  std::string model, description, symptoms, repairs;
  std::vector<int> parts;
  double price;
};