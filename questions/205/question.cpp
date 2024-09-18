#include <iostream>

int main() {
  constexpr unsigned int id = 100;
  unsigned char array[] = { id % 3, id % 5 };
  std::cout << static_cast<unsigned int>(array[0])
            << static_cast<unsigned int>(array[1]) ;
}