#include <iostream>
#include <iomanip>
#include <memory>

#include "calculator.hh"
#include "calculator_oop.hh"
#include "calculator_proc.hh"

using namespace std;

int main()
{
  unique_ptr<calculator> c;

  while (true)
  {
    cout << "Select class (1 - calculator_proc, 2 - calculator_oop): " << endl;
    int x;
    cin >> x;

    if (x == 1)
    {
      c = make_unique<calculator_proc>();
      break;
    }
    if (x == 2)
    {
      c = make_unique<calculator_oop>();
      break;
    }
  }

  while (true)
  {
    double operand1, operand2;
    string operator_;

    cin >> operand1 >> operator_ >> operand2;

    cout << " = " << fixed << c->calculate(operator_, operand1, operand2) << endl;
  }
}