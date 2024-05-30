Since the functions `f` are declared inside namespaces, and the call `f(x::C())` is unqualified (not preceded by `x::` or `y::`), this would normally not compile.

However, due to [argument-dependent name lookup](https://en.wikipedia.org/wiki/Argument-dependent_name_lookup) a.k.a. "Koenig lookup", the behavior is well defined.

With argument-dependent name lookup, the namespaces of the *arguments to* a function is added to the set of namespaces to be searched for that function. Since we're passing an `x::C` to `f`, the namespace `x` is also searched, and the function `x::f` is found.

§[basic.lookup.argdep]¶1 in the C++ standard:
"When the postfix-expression in a function call (§8.2.2) is an unqualified-id, other namespaces not considered during the usual unqualified lookup (§6.4.1) may be searched(...). These modifications to the search depend on the types of the arguments (...)."

`f` is an unqualified-id, so "other namespaces" may be searched.

§[basic.lookup.argdep]¶2 has more:
"For each argument type T in the function call, there is a set of zero or more associated namespaces and a set of zero or more associated classes to be considered. The sets of namespaces and classes are determined entirely by the types of the function arguments (...). The sets of namespaces and classes are determined in the following way:
(...)
- If T is a class type (including unions), its associated classes are: the class itself; the class of which it is a member, if any; and its direct and indirect base classes. Its associated namespaces are the namespaces of which its associated classes are members."

`T` in our case is `C`, so it's associated classes is just `C`. It's associated namespaces is then just `x`, which is searched to find a function `f`.
