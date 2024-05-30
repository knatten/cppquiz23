#include <iostream>

int main()
{
    int i = 1;
    int& j;
    j = i;
    std::cout << j;
}