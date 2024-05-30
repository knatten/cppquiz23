#include <type_traits>
#include <iostream>
#include <string>

template<typename T>
int f()
{
    if constexpr (std::is_same_v<T, int>) { return 0; }
    else { return std::string{}; }
}

int main()
{
    std::cout << f<int>();
}