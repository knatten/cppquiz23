You are actually allowed to specify fewer initializers than a struct/class has members, as long as that struct/class is an aggregate.

§[dcl.init.aggr]¶5:

> For a non-union aggregate, each element that is not an explicitly initialized element is initialized as follows:
>
> — If the element has a default member initializer (§[class.mem]), the element is initialized from that initializer.
>
> — Otherwise, if the element is not a reference, the element is copy-initialized from an empty initializer list (§[dcl.init.list]).
>
> — Otherwise, the program is ill-formed.

In this case, the second bullet point applies, and the program is actually well-formed. You may not even get a warning about this, for instance both GCC and Clang require `-Wextra` to warn about it.

The rule that allows fewer initializers only applies to a "non-union aggregate". Is `S` a non-union aggregate? It's a `struct`, so it's not a `union`. Is it also an aggregate? An aggregate is basically any array or class with nothing "special" going on in initialization, such as constructors etc.

§[dcl.init.aggr]¶1:

> An *aggregate* is an array or a class (§[class]) with
>
> — no user-declared or inherited constructors (§[class.ctor]),
>
> — no private or protected direct non-static data members (§[class.access]),
>
> — no private or protected direct base classes (§[class.access.base]), and
>
> — no virtual functions (§[class.virtual]) or virtual base classes (§[class.mi]).

`struct S` has none of the above, so it's an aggregate.