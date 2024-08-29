#include <iostream>
#include <vector>

typedef std::vector<int> TVint;

int main() {
    TVint t(1);
    std::cout << (typeid(t) == typeid(std::vector<int>));
}