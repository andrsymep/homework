#include "logger.hh"

#include <string>
#include <ctime>

#include "logger.hh"
#include "log_level.hh"

template <typename... Args>
void logger::log(log_level level, Args... args)
{
  (_log("[" + log_level_to_string(level) + " " + std::to_string(std::time(nullptr)) + "] " + args), ...);
}