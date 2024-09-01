According to the §[dcl.fct.def.delete]¶2:

> A program that refers to a deleted function implicitly or explicitly, other than to declare it, is ill-formed.

Does `S{}` refer to the deleted constructor? That depends on whether this is value-initialization or aggregate initialization. In the case of value-initialization, the constructor will be called, but in the case of aggregate initialization, no constructor is called.

The rules for whether a struct is an aggregate are quite complex §[dcl.init.aggr]¶1:

> An *aggregate* is an array or a class with
> - no user-declared or inherited constructors,
> - no private or protected direct non-static data members,
> - no private or protected direct base classes, and
> - no virtual functions or virtual base classes.

Here, the `S` default constructor is considered user-declared, so `S` isn't an aggregate, and `S{}` is using value initialization, and the program is ill-formed.

Note that this behavior changed in C++20 ([P1008](https://wg21.link/p1008)). Previously, a constructor that was only user-declared but not user-provided did not prevent a class from being an aggregate. So prior to C++20, this question did actually compile.