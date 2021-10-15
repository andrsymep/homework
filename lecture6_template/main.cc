#include <iostream>

template <int N>
constexpr int max_number()
{
  return 10 * max_number<N - 1>() + 9;
}

template <>
constexpr int max_number<0>()
{
  return 0;
}

using namespace std;

int main()
{
  cout << max_number<0>() << endl;
  cout << max_number<1>() << endl;
  cout << max_number<2>() << endl;
  cout << max_number<3>() << endl;
  cout << max_number<4>() << endl;
  cout << max_number<5>() << endl;
  cout << max_number<6>() << endl;
  cout << max_number<7>() << endl;
  cout << max_number<8>() << endl;
  cout << max_number<9>() << endl;
}