The rules for whether a struct is an aggregate are quite complex §[dcl.init.aggr]¶1:

> An aggregate is an array or a class with no user-provided, explicit, or inherited constructors, no private or protected non-static data members, no virtual functions, and no virtual, private, or protected base classes.

Here, the `S` default constructor is considered user-declared, but not user-provided. §[dcl.fct.def.default]¶5:

> A function is user-provided if it is user-declared and not explicitly defaulted or deleted on its first declaration. 

So `S` is considered an aggregate, and `S{}` is using aggregate initialization, which does not call any constructor.

The initialization list `{}` in `auto s = S{};` has no elements though, so the value of `x` is not specified. In this case, `x` will be copy-initialized from an empty initializer list. §[sdcl.init.aggr]¶8:

> If there are fewer initializer-clauses in the list than there are elements in a non-union aggregate, then each element not explicitly initialized is initialized as follows: (...) the element is copy-initialized from an empty initializer list.

And initializing from an empty initializer list results in value-initialization §[dcl.init.list]¶3.10:

> Otherwise, if the initializer list has no elements, the object is value-initialized.

And value-initializing an `int` sets it to zero.

Note that this behavior is changed in C++20 (P1008R1), where `S` is not an aggregate because it has a user-declared constructor, and so this code would be a guaranteed compile error.