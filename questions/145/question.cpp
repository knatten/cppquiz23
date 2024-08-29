#include <iostream>

struct E
{
  E() { std::cout << "1"; }
  E(const E&) { std::cout << "2"; }
  ~E() { std::cout << "3"; }
};

E f()
{
  return E();
}

int main()
{
  f();
}