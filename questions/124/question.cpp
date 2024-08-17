#include <iostream>

struct A {};
struct B {};

template<typename T = A>
struct X;

template<>
struct X<A> {
    static void f() { std::cout << 1; }
};

template<>
struct X<B> {
    static void f() { std::cout << 2; }
};

template<template<typename T = B> class C>
void g() {
    C<>::f();
}

int main() {
    g<X>();
}