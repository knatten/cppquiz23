#include <iostream>

void f(int& a, const int& b) {
  std::cout << b;
  a = 1;
  std::cout << b;
}

int main(){
  int x = 0;
  f(x,x);
}