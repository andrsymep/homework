#pragma once

#include <string>

class calculator
{
public:
  virtual double calculate(std::string operator_, double operand1, double operand2) = 0;
};