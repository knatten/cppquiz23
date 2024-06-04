According to the [dcl.fct.def.delete]¶2:

> A program that refers to a deleted function implicitly or explicitly, other than to declare it, is ill-formed.

Is `S{}` refers to the deleted constructor? It depends on whether it will be value-initialization or aggregate initialization. In the case of value-initialization, the constructor will be called, and aggregate initialization does not call any constructors.

The rules for whether a struct is an aggregate are quite complex §[dcl.init.aggr]¶1:

> An aggregate is an array or a class with no user-declared or inherited constructors, no private or protected non-static data members, no virtual functions, and no virtual, private, or protected base classes.

Here, the `S` default constructor is considered user-declared, so `S` isn't an aggregate, and `S{}` is using value initialization, and the program is ill-formed.
