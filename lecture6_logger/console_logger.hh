#pragma once

#include "logger.hh"

class console_logger : public logger
{
private:
  void _log(std::string message) override;
};