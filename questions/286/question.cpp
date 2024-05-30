#include<iostream>

int main()
{
    unsigned short x=0xFFFF;
    unsigned short y=0xFFFF;
    auto z=x*y;
    std::cout << (z > 0);
}