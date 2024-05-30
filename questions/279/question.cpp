#include <iostream>
#include <variant>

struct C
{
    C() : i(1){}
    int i;
};

struct D
{
    D() : i(2){}
    int i;
};

int main()
{
    const std::variant<C,D> v;
    std::visit([](const auto& val){ std::cout << val.i; }, v);
}