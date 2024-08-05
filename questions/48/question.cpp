#include <iostream>
#include <string>
#include <future>

int main() {
  std::string x = "x";

  (void)std::async(std::launch::async, [&x]() {
    x = "y";
  });
  (void)std::async(std::launch::async, [&x]() {
    x = "z";
  });

  std::cout << x;
}
