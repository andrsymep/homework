#include "console_logger_factory.hh"
#include "console_logger.hh"

logger *console_logger_factory::create_logger()
{
  return new console_logger();
}