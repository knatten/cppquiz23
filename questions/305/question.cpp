#include <iostream>

void print(int x, int y)
{
    std::cout << x << y;
}

int main() {
    int i = 0;
    print(++i, ++i);
    return 0;
}