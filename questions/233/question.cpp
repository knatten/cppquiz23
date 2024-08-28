#include <type_traits>
#include <iostream>

struct X {
    int f() const&&{
        return 0;
    }
};

int main() {
    auto ptr = &X::f;
    std::cout << std::is_same_v<decltype(ptr), int()>
              << std::is_same_v<decltype(ptr), int(X::*)()>;
}