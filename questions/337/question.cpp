#include <iostream>
#include <type_traits>

int main() {
    auto a = "Hello, World!";
    std::cout << std::is_same_v<decltype("Hello, World!"), decltype(a)>;

    return 0;
}