#include <iostream>

int main() {
  unsigned short zero = 0, one = 1;
  if (zero - one < zero)
    std::cout << "less";
  else
    std::cout << "more";
}