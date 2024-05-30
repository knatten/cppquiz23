#include <iostream>

auto sum(int i)
{
  if (i == 1)
    return i;
  else
    return sum(i-1)+i;
}

int main()
{
    std::cout << sum(2);
}