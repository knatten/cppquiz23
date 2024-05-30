#include <iostream>

extern "C" int x;
extern "C" { int y; }

int main() {

	std::cout << x << y;

	return 0;
}