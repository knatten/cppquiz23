#include <string>
#include <iostream>

int main() {
  using namespace std::string_literals;
  std::string s1("hello world",5); 
  std::string s2("hello world"s,5); 

  std::cout << s1 << s2;
}