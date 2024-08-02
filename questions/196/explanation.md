Since the functions `f` are declared inside namespaces, and the call `f(x::C())` is unqualified (not preceded by `x::` or `y::`), this would normally not compile.

However, due to [argument-dependent name lookup](https://en.wikipedia.org/wiki/Argument-dependent_name_lookup) a.k.a. "Koenig lookup", the behavior is well defined.

With argument-dependent name lookup, the namespaces of the *arguments to* a function is added to the set of namespaces to be searched for that function. Since we're passing an `x::C` to `f`, the namespace `x` is also searched, and the function `x::f` is found.

§[basic.lookup.argdep]¶1:
> When the *postfix-expression* in a function call is an *unqualified-id*, and unqualified lookup for the name in the *unqualified-id* does not find any [declaration] then lookup for the name also includes the result of *argument-dependent lookup* in a set of associated namespaces that depends on the types of the arguments

`f` is an unqualified-id, so "other namespaces" may be searched.

§[basic.lookup.argdep]¶3:
> For each argument type `T` in the function call, there is a set of zero or more *associated entities* to be considered. The set of entities is determined entirely by the types of the function arguments (...). The set of entities is determined in the following way:
(...)
>
> — If `T` is a class type (including unions), its *associated entities* are: the class itself; the class of which it is a member, if any; and its direct and indirect base classes. (...)

The relevant associated entity here is the class `C` itself.

§[basic.lookup.argdep]¶4 concludes:
> The *associated namespaces* for a call are the innermost enclosing non-inline namespaces for its associated entities as well as every element of the inline namespace set of those namespaces. Argument-dependent lookup finds all declarations of functions and function templates that
>
> — are found by a search of any associated namespace
> (...)

The associated entity is `C`, and its innermost enclosing namespace is `x`, which is searched to find `f`.
