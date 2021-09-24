#include <string>
#include <cmath>

#include "operations.hh"

using std::string;

#define IMPLEMENT_OPERATION(name, expression, token)                    \
  double operation_##name::operator()(double operand1, double operand2) \
  {                                                                     \
    return expression;                                                  \
  }                                                                     \
                                                                        \
  string operation_##name::get_token()                                  \
  {                                                                     \
    return token;                                                       \
  }

IMPLEMENT_OPERATION(add, operand1 + operand2, "+")
IMPLEMENT_OPERATION(sub, operand1 - operand2, "-")
IMPLEMENT_OPERATION(mul, operand1 *operand2, "*")
IMPLEMENT_OPERATION(div, operand1 / operand2, "/")
IMPLEMENT_OPERATION(pow, pow(operand1, operand2), "**")