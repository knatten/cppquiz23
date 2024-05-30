#include <functional>
#include <iostream>

template <typename T>
void call_with(std::function<void(T)> f, T val)
{
    f(val);
}

int main()
{
    auto print = [] (int x) { std::cout << x; };
    call_with(print, 42);
}