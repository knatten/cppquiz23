#include <future>
#include <iostream>

int main()
{
    auto f = std::async(std::launch::async, [](){ throw 0; });
    try {
        f.wait();
    } catch (...)
    {
        std::cout << 1;
    }
    std::cout << 2;
}