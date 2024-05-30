#include <iostream>

struct Printer
{
    Printer() { std::cout << 1; }
};

template <typename T>
struct C
{
    C(T i) { std::cout << i; }
    static inline Printer printer{};
};


int main()
{
    C c(2);
}