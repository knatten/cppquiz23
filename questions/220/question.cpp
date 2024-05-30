#include <iostream>

bool f() { std::cout << 'f'; return false; }
char g() { std::cout << 'g'; return 'g'; }
char h() { std::cout << 'h'; return 'h'; }

int main() {
    char result = f() ? g() : h();
    std::cout << result;
}