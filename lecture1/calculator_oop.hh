#pragma once

#include <string>
#include <vector>
#include <memory>
#include <unordered_map>

#include "calculator.hh"
#include "operations.hh"

class calculator_oop : public calculator
{
public:
  calculator_oop();
  double calculate(std::string operator_, double operand1, double operand2) override;

private:
  std::unordered_map<std::string, std::shared_ptr<operation>> token_to_operation;

  static std::vector<std::shared_ptr<operation>>
      operations;
};