#include <cstdlib>
#include <iostream>

struct S {
    char s;
    S(char s): s{s} {}
    ~S() { std::cout << s; }
};

S a('a');

int main() {
    S b('b');
    std::exit(0);
}