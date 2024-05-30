#include <iostream>

struct S {
  operator void() {
    std::cout << "F";
  }
};

int main() {
  S s;
  (void)s;
  static_cast<void>(s);
  s.operator void();
}