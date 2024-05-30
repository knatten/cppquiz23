#include <iostream>

struct S
{
  S() = delete;
  int x;
};

int main()
{
  auto s = S{};
  std::cout << s.x;
}