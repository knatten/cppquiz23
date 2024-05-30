#include <future>
#include <iostream>

int main()
{
    try {
        std::promise<int> p;
        std::future<int> f1 = p.get_future();
        std::future<int> f2 = p.get_future();
        p.set_value(1);
        std::cout << f1.get() << f2.get();
    } catch(const std::exception& e)
    {
        std::cout << 2;
    }
}