#include <iostream>

struct C {
    int& i;
};

int main() {
    int x = 1;
    int y = 2;

    C c{x};
    c.i = y;

    std::cout << x << y << c.i;
}