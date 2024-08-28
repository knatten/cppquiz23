#include <variant>
#include <iostream>
 
int main() {
   std::variant<int, double, char> v;
   std::cout << v.index();
}