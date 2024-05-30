#include <iostream>

void f()
{
    std::cout << "1";
}

template<typename T>
struct B
{
    void f()
    {
        std::cout << "2";
    }
};

template<typename T>
struct D : B<T>
{
    void g()
    {
        f();
    }
};

int main()
{
    D<int> d;
    d.g();
}