#include <iostream>
#include <typeinfo>

struct Base
{
};

struct Derived : Base
{
};

int main()
{
    Derived d;
    Base& b = d;
    std::cout << (typeid(b) == typeid(Derived));
}