#include <iostream>

struct S;

S foo(S s); //S has only been forward declared at this point

struct S{};

S foo(S s) { return {}; }

int main(){
    const S s = foo(S{});
    std::cout << "ok";
}