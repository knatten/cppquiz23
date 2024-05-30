#include <iostream>

class A {};

class B {
public:
    int x = 0;
};

class C : public A, B {};

struct D : private A, B {};


int main()
{
    C c;
    c.x = 3;

    D d;
    d.x = 3;

    std::cout << c.x << d.x;
}