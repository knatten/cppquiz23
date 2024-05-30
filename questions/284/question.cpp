#include <iostream>
#include <string>

auto main() -> int {
  std::string out{"Hello world"};
  std::cout << (out[out.size()] == '\0');
}