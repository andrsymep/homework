#pragma once

#include <string>

class operation
{
public:
  virtual double operator()(double operand1, double operand2) = 0;
  virtual std::string get_token() = 0;
};

#define DEFINE_OPERATION(name)                                    \
  class operation_##name : public operation                       \
  {                                                               \
  public:                                                         \
    double operator()(double operand1, double operand2) override; \
    std::string get_token() override;                             \
  };

DEFINE_OPERATION(add)
DEFINE_OPERATION(sub)
DEFINE_OPERATION(mul)
DEFINE_OPERATION(div)
DEFINE_OPERATION(pow)