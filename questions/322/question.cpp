#include <iostream>
#include <stdexcept>

int main()
{
    goto inside;
    try
    {
        inside:
        throw std::runtime_error("oops");
    }
    catch(...)
    {
        std::cout << 1;
    }
    std::cout << 2;
}