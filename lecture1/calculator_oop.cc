#include <stdexcept>

#include "calculator_oop.hh"

using std::make_shared;
using std::shared_ptr;
using std::string;
using std::vector;

vector<shared_ptr<operation>> calculator_oop::operations = {
    make_shared<operation_add>(),
    make_shared<operation_sub>(),
    make_shared<operation_mul>(),
    make_shared<operation_div>(),
    make_shared<operation_pow>(),
};

calculator_oop::calculator_oop()
{
  for (auto &operation : operations)
  {
    token_to_operation[operation->get_token()] = operation;
  }
}

double
calculator_oop::calculate(string operator_, double operand1, double operand2)
{
  if (token_to_operation.count(operator_) == 0)
  {
    throw new std::invalid_argument(std::string("Invalid operator '") + operator_ + "'");
  }

  return token_to_operation[operator_]->operator()(operand1, operand2);
}
