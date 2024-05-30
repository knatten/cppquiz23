#include <iostream>

volatile int a;

int main() {
  std::cout << (a + a);
}