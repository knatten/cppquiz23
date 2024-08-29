#include <vector>
#include <iostream>

std::vector<int> v;

int f1() {
  v.push_back(1);
  return 0;
}

int f2() {
  v.push_back(2);
  return 0;
}

void g(int, int) {}

void h() {
  g(f1(), f2());
}

int main() {
  h();
  h();
  std::cout << (v[0] == v[2]);
}