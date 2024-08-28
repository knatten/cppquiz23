#include <iostream>
#include <type_traits>

int main() {
    std::cout << std::is_const_v<const int *>
              << std::is_const_v<const int [1]>
              << std::is_const_v<const int **>
              << std::is_const_v<const int (*)[1]>
              << std::is_const_v<const int *[1]>
              << std::is_const_v<const int [1][1]>;
}