#pragma once

#include <string>

enum log_level
{
  INFO,
  WARNING,
  ERROR
};

std::string log_level_to_string(log_level level);