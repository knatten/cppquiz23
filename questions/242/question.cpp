#include <iostream>
#include <type_traits>
#include <utility>

void g(int&) { std::cout << 'L'; }
void g(int&&) { std::cout << 'R'; }

template<typename T>
void f(T&& t) {
    if (std::is_same_v<T, int>) { std::cout << 1; } 
    if (std::is_same_v<T, int&>) { std::cout << 2; } 
    if (std::is_same_v<T, int&&>) { std::cout << 3; } 
    g(std::forward<T>(t));
}

int main() {
    f(42);
    int i = 0;
    f(i);
}