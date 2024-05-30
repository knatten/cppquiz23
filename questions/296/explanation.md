You are actually allowed to specify fewer initializers than a struct/class has members, as long as that struct/class is an aggregate.

§[dcl.init.aggr]¶8:
> If there are fewer initializer-clauses in the list than there are elements in a non-union aggregate, then each element not explicitly initialized is initialized as follows:
 — If the element has a default member initializer (12.2), the element is initialized from that initializer.
 — Otherwise, if the element is not a reference, the element is copy-initialized from an empty initializer list (11.6.4).
 — Otherwise, the program is ill-formed.

In this case, the second bullet point applies, and the program is actually well formed. You may not even get a warning about this, for instance both gcc and clang requires `-Wextra` to warn about it.

The rule that allows to few initializers only applies to a "non-union aggregate". Is `S` a non-union aggregate? It's a `struct`, so it's not a `union`. Is it also an aggregate? An aggregate is basically any array or class with nothing "special" going on in initialization, such as constructors etc.

§[dcl.init.aggr]¶1:
> An aggregate is an array or a class with
— no user-provided, explicit, or inherited constructors,
— no private or protected non-static data members,
— no virtual functions, and
— no virtual, private, or protected base classes

`struct S` has none of the above, so it's an aggregate.