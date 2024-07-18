#include <iostream>

int main() {
    int a = '0';
    char const &b = a;
    std::cout << b;
    a++;
    std::cout << b;
}