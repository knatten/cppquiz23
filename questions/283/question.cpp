#include <iostream>

class show_id
{
public:
    ~show_id() { std::cout << id; }
    int id;
};

int main()
{
    delete[] new show_id[3]{ {0}, {1}, {2} };
}