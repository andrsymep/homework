#include <iostream>

#include "console_logger.hh"

void console_logger::_log(std::string message)
{
  std::cout << message << std::endl;
}