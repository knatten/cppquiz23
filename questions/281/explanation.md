We're initializing `c2` from an rvalue, so it would be preferable to have a move constructor available. But since we declare a copy constructor, we do not get an implicit move constructor:

§[class.copy.ctor]¶8.1:

> If the definition of a class `X` does not explicitly declare a move constructor, a non-explicit one will be implicitly declared as defaulted if and only if
>
> — `X` does not have a user-declared copy constructor,

So we don't have a move constructor. But can we still initialize `c2`?

When overload resolution looks for a constructor to use, the candidate functions are all the constructors of the class. If we had both a copy and a move constructor, the move constructor would be picked as the best viable function.

However, in this case we only have a copy constructor. Is it too a viable function? For it to be viable, we need to be able to bind `const C&` to the xvalue `std::move(c)`.

§[dcl.init.ref] has the details for initializing references. It first discusses binding to lvalues, which is not the case here, then it gets to §[dcl.init.ref]¶5.2:

> — Otherwise, if the reference is an lvalue reference to a type that is not const-qualified or is volatile-qualified, the program is ill-formed.

Our reference `const C&` is an lvalue reference to non-volatile const, so this clause doesn't apply here either. It continues:

> — Otherwise, if the initializer expression (...) is an rvalue (...) then the initializer expression (...) is called the converted initializer. (...) In any case, the reference binds to the resulting glvalue (or to an appropriate base class subobject).

We won't explain value categories here (see [lvalues, rvalues, glvalues, prvalues, xvalues, help!](https://blog.knatten.org/2018/03/09/lvalues-rvalues-glvalues-prvalues-xvalues-help/) for an introduction), but the xvalue `std::move(c)` is *both* an rvalue and a glvalue. So the clause "if [it] is an rvalue" above applies, as does "the resulting glvalue".

So the `const C&` in the copy constructor is bound to the glvalue `std::move(c)`. The copy constructor is indeed a viable function, and is used to construct `c2`.