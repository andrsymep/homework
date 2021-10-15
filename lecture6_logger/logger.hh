#pragma once

#include <string>

#include "log_level.hh"

class logger
{
public:
  template <typename... Args>
  void log(log_level level, Args... args);

private:
  virtual void _log(std::string message) = 0;
};

#include "logger.tcc"