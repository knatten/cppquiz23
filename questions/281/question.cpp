#include <iostream>

class C
{
public:
    C(){}
    C(const C&){} // User-declared, disables move constructor
};

int main()
{
    C c;
    C c2(std::move(c));
    std::cout << "ok";
}