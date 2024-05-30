We're trying to default-initialize `c`. This is not allowed since it is `const` and `C` has a defaulted (not user-provided) constructor.

§[dcl.init]¶7:
> If a program calls for the default-initialization of an object of a const-qualified type `T`, `T` shall be a const-default-constructible class type or array thereof.

Is `C` const-default-constructible?

§[dcl.init]¶7 again:
> A class type `T` is const-default-constructible if default-initialization of `T` would invoke a user-provided constructor of `T` (not inherited from a base class) or if
- each direct non-variant non-static data member `M` of `T` has a default member initializer or, if `M` is of class type `X` (or array thereof), `X` is const-default-constructible,
- if `T` is a union with at least one non-static data member, exactly one variant member has a default member initializer,
- if `T` is not a union, for each anonymous union member with at least one non-static data member (if any), exactly one non-static data member has a default member initializer, and
- each potentially constructed base class of `T` is const-default-constructible.

`C` does not have a user-provided constructor, and the points below don't apply either.

There are several ways we could make `C` const-default-constructible:
- Give `int i` a default member initializer: `int i{0}`.
- Remove ` = default` from the constructor,  and instead do `C::C() = default;` separately outside the class definition. This constructor now counts as user-provided.
- Manually provide a constructor: `C() {}`