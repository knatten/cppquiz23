#include <iostream>

using Func = int();

struct S {
    Func f;
};

int S::f() { return 1; }

int main() {
    S s;
    std::cout << s.f();
}