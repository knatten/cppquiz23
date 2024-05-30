#include <iostream>

int main() {
  void * p = &p;
  std::cout << bool(p);
}