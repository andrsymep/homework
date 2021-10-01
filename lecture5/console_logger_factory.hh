#include "logger_factory.hh"

class console_logger_factory : logger_factory
{
private:
  logger *create_logger() override;
};