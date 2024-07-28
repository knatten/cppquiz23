#include <stdexcept>
#include <exception>
#include <iostream>

int main() {
    try {
        throw std::out_of_range("");
    } catch (std::exception& e) {
        std::cout << 1;
    } catch (std::out_of_range& e) {
        std::cout << 2;
    }
}