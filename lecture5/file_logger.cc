#include <iostream>

#include "file_logger.hh"

file_logger::file_logger()
{
  file.open("example.txt", std::ios::out);
}

void file_logger::_log(std::string message)
{
  file << message << std::endl;
}