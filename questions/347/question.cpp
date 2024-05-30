#include <iostream>
#include <type_traits>

template <typename T>
void foo(T& x)
{
    std::cout << std::is_same_v<const int, T>;
}

template <typename T>
void bar(const T& x)
{
    std::cout << std::is_same_v<const int, T>;
}

int main()
{
    const int i{};
    int j{};

    foo(i);
    foo(j);
    bar(i);
    bar(j);

}