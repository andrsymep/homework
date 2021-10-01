#include "file_logger_factory.hh"
#include "file_logger.hh"

logger *file_logger_factory::create_logger()
{
  return new file_logger();
}