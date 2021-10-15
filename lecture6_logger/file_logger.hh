#pragma once

#include <fstream>
#include <iostream>

#include "logger.hh"

class file_logger : public logger
{
public:
  file_logger();

private:
  void _log(std::string message) override;

  std::ofstream file;
};