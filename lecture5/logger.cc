#include <string>
#include <ctime>

#include "logger.hh"
#include "log_level.hh"

void logger::log(log_level level, std::string message)
{
  _log("[" + log_level_to_string(level) + " " + std::to_string(std::time(nullptr)) + "] " + message);
}