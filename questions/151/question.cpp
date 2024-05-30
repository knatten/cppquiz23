#include <iostream>
#include <type_traits>

int main()
{
    std::cout << std::is_signed<char>::value;
}