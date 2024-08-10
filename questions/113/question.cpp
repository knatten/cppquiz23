#include <iostream>

template<typename T>
void f(T) {
    std::cout << 1;
}

template<>
void f(int) {
    std::cout << 2;
}

void f(int) {
    std::cout << 3;
}

int main() {
    f(0.0);
    f(0);
    f<>(0);
}