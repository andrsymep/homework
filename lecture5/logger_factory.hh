#pragma once

#include "logger.hh"

class logger_factory
{
public:
  virtual logger *create_logger() = 0;
};