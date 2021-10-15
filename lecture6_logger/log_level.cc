#include "log_level.hh"

std::string log_level_to_string(log_level level)
{
  switch (level)
  {
  case log_level::INFO:
    return "INFO";
  case log_level::WARNING:
    return "WARN";
  case log_level::ERROR:
    return "ERRO";
  }
}