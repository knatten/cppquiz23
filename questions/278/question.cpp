#include <iostream>
#include <tuple>

int main()
{
    const auto t = std::make_tuple(42, 3.14, 1337);
    std::cout << std::get<int>(t);
}