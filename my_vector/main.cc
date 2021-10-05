#include <iostream>

#include "vector.hh"

using std::cout;
using std::endl;

int main()
{
  vector<int> v(2, 1);

  v.push_back(1);
  v.push_back(2);
  v.push_back(3);
  v.push_back(4);

  cout << v.size() << " " << v.capacity() << endl;

  v.push_back(5);

  cout << v.size() << " " << v.capacity() << endl;

  v.pop_back();
  v.pop_back();
  v.pop_back();
  v.pop_back();

  cout << v.size() << " " << v.capacity() << endl;

  v.pop_back();

  cout << v.empty() << endl;

  v[0] = 1;

  vector<int> q;
  q = std::move(v);

  cout << q.size() << " " << v.size() << endl;
}