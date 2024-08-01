#include <iostream>
#include <map>

bool default_constructed = false;
bool constructed = false;
bool assigned = false;

class C {
public:
    C() { default_constructed = true; }
    C(int) { constructed = true; }
    C& operator=(const C&) { assigned = true; return *this;}
};

int main() {
    std::map<int, C> m;
    m[7] = C(1);

    std::cout << default_constructed << constructed << assigned;
}