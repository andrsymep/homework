#include <memory>

#include "console_logger.hh"
#include "console_logger_factory.hh"
#include "file_logger.hh"
#include "file_logger_factory.hh"

int main()
{
  console_logger cl;
  cl.log(log_level::INFO, "Info.");
  cl.log(log_level::ERROR, "Something bad happened!");

  file_logger fl;
  fl.log(log_level::INFO, "File logger");
  fl.log(log_level::WARNING, "Warning in file");
}