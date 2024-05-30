#include <future>
#include <iostream>

int main()
{
    std::promise<int> p;
    std::future<int> f = p.get_future();
    p.set_value(1);
    std::cout << f.get();
    std::cout << f.get();
}