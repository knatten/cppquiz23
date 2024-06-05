#include <functional>
#include <iostream>

struct Q {
    int v = 0;

    Q() { std::cout << "D"; }
    Q(const Q&) { std::cout << "C"; }
    Q(Q&&) { std::cout << "M"; }

    void change() { ++v; }
    void func() { std::cout << v; }
};

void takeQfunc(std::function<void(Q)> qfunc) {
    Q q;
    q.func();
    qfunc(q);
    q.func();
}

int main() {
    takeQfunc([](Q&& q) { q.change(); });
}