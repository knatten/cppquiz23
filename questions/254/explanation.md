The constness of parameters are not part of the function type.

§[dcl.fct]¶5 in the standard:

> The type of a function is determined using the following rules. The type of each parameter (including function parameter packs) is determined from its own *parameter-declaration* (§[dcl.decl]). (...) After producing the list of parameter types, any top-level *cv-qualifier*s modifying a parameter type are deleted when forming the function type.

So in the first case, the type of `void(const int)` is actually `void(int)`. The types are the same, and `1` is printed.

What about the second case? Here the parameter types are "pointer to `int`" and "pointer to `const int`", respectively. The pointers themselves are not `const`, so there's no `const` to remove. The types of the functions are different, and `0` is printed.

Why is the constness of parameters not part of the function type? When an argument is passed by value, a copy is made, and the original argument is never modified anyway. So whether the parameter is `const` or not does not matter to the caller, it's only relevant inside the function.