#include <cmath>
#include <stdexcept>
#include <iostream>

#include "calculator_proc.hh"

double calculator_proc::calculate(std::string operator_, double operand1, double operand2)
{
  if (operator_ == "+")
  {
    return add(operand1, operand2);
  }

  if (operator_ == "-")
  {
    return sub(operand1, operand2);
  }

  if (operator_ == "*")
  {
    return mul(operand1, operand2);
  }

  if (operator_ == "/")
  {
    return div(operand1, operand2);
  }

  if (operator_ == "**")
  {
    return pow(operand1, operand2);
  }

  throw new std::invalid_argument(std::string("Invalid operator '") + operator_ + "'");
}

double calculator_proc::add(double a, double b)
{
  return a + b;
}

double calculator_proc::sub(double a, double b)
{
  return a - b;
}

double calculator_proc::mul(double a, double b)
{
  return a * b;
}

double calculator_proc::div(double a, double b)
{
  return a / b;
}

double calculator_proc::pow(double a, double b)
{
  return ::pow(a, b);
}
