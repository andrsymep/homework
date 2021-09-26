#pragma once

#include <vector>
#include <string>

enum TextAlignment
{
  LEFT,
  CENTER,
  RIGHT
};

class column
{
public:
  std::string header;
  std::vector<std::string> data;

  TextAlignment alignment = LEFT;

  size_t size() const;
};