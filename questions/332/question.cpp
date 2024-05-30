#include <iostream>

struct S {
    template <typename Callable>
    void operator[](Callable f) {
        f();
    }
};

int main() {
    auto caller = S{};
    caller[ []{ std::cout << "C";} ];
}