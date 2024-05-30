#include <iostream>

struct override {};

struct Base {
    virtual override f() = 0;
};

struct Derived : Base {
    virtual auto f() -> override override{
        std::cout << "1";
        return override();
    }
};

int main() {
    Derived().f();
}