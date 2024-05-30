Providing a definition for a pure virtual function is valid, as long as it is not defined directly in the function declaration. So defining `Base::f()` outside of `Base` is ok.

§[class.abstract]¶2 in the C++ standard:
> A pure virtual function need be defined only if called with, or as if with (§15.4), the qualified-id syntax (§8.1).

This implicitly says that a pure virtual function can in fact be defined. Furthermore:

> A function declaration cannot provide both a pure-specifier and a definition

Which is why we have to define it outside the declaration[1]. Now to the output of the program:

`object.f()` calls `Derived::f()`, returning `2`.

`((Base&)object).f()` casts `object` to a `Base&` before calling `f()`, but since `f()` is a virtual function, `Derived::f()` is still called, returning `2`.

[1]: This is a non-normative note; the actual normative wording that disallows it is the grammar for a function-definition does not include a pure-specifier.
