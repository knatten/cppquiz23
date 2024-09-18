#include <iostream>
#include <typeinfo>

struct A {};

int main()
{
    std::cout<< (&typeid(A) == &typeid(A));
}