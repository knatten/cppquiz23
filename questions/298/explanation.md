Exception specifiers do not depend on whether the function can actually throw in practice. So the presence of `throw` in the constructor and destructor does not influence the exception specifiers.

For the constructor, the usual rules for exception specifiers apply. §[except.spec]¶3:
> If a declaration of a function does not have a noexcept-specifier, the declaration has a potentially throwing exception specification unless it is a destructor or a deallocation function or is defaulted on its first declaration

The constructor is not a destructor or a deallocation function, nor is it defaulted, so it is potentially trhrowing.


For the destructor, there are special rules.
§[except.spec]¶8:
> The exception specification for an implicitly-declared destructor, or a destructor without a noexcept-specifier, is potentially-throwing if and only if any of the destructors for any of its potentially constructed subojects is potentially throwing.

Note that this rule also applies to our user provided destructor! We don't provide a noexcept-specifier, and `S` does not have any subobjects (members or bases) with potentially throwing destructors. So unlike the constructor, the destructor is potentially throwing.