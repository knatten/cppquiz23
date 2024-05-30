#include <iostream>
#include <stdexcept>
#include <type_traits>

struct S {
    S() {
        throw std::runtime_error("");
    }
    ~S() {
        throw std::runtime_error("");
    }
};

int main() {
    std::cout
        << (std::is_nothrow_constructible_v<S> ? 'y' : 'n')
        << (std::is_nothrow_destructible_v<S> ? 'y' : 'n');
}