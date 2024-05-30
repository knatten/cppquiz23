#include <iostream>
#include <stdexcept>

struct A {
    A(char c) : c_(c) {}
    ~A() { std::cout << c_; }
    char c_;
};

struct Y { ~Y() noexcept(false) { throw std::runtime_error(""); } };

A f() {
    try {
        A a('a');
        Y y;
        A b('b');
        return {'c'};
    } catch (...) {
    }
    return {'d'};
}

int main()
{
    f();
}