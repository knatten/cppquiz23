#include <iostream>

template <typename T>
struct A {
    static_assert(false);
};

int main() {
    std::cout << 1;
}