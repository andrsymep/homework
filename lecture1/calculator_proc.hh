#pragma once

#include <string>

#include "calculator.hh"

class calculator_proc : public calculator
{
public:
  double calculate(std::string operator_, double operand1, double operand2) override;

private:
  double add(double a, double b);
  double sub(double a, double b);
  double mul(double a, double b);
  double div(double a, double b);
  double pow(double a, double b);
};