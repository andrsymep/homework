#include <iostream>
#include <utility>
// #include <memory>

#include "unique_ptr.hh"
#include "shared_ptr.hh"

using namespace std;

class greeter
{
private:
  string name;

public:
  greeter(const string &name) : name(name)
  {
    cout << name << " created!" << endl;
  }

  ~greeter()
  {
    cout << name << " destructed" << endl;
  }

  void say()
  {
    cout << name
         << " says hello" << endl;
  }
};

int main()
{
  unique_ptr ptr(new greeter("unique"));

  unique_ptr a = move(ptr);

  // *ptr = 5;
  a->say();

  shared_ptr s1(new greeter("shared"));
  {
    auto s2 = s1;
    auto s3 = s2;
    auto s4 = s2;
    s3->say();
    (*s3).say();
  }
  auto s5 = move(s1);
  s5->say();
}
