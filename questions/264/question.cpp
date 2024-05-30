#include <iostream>

struct C {
    C() = default;
    int i;
};

int main() {
    const C c;
    std::cout << c.i;
}