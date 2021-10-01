#pragma once

#include <string>

#include "log_level.hh"

class logger
{
public:
  void log(log_level level, std::string message);

private:
  virtual void _log(std::string message) = 0;
};