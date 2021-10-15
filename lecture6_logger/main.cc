#include "console_logger.hh"

int main()
{
  console_logger cl;
  cl.log(log_level::INFO, "hey", "there");
  cl.log(log_level::WARNING, "general", "kenobi");
}