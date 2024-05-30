`decltype` is used twice, once with `"Hello World"` and once with `a`. §[dcl.type.simple]¶4 has the details:

For `decltype("Hello World")`, we have:
> otherwise, if `e` is an lvalue, `decltype(e)` is `T&`, where `T` is the type of `e`;

A string literal is an lvalue, and its type is "array of n `const char`" (§[lex.string]¶8), so `decltype("Hello, World!")` is `const char(&)[14]`.

For `decltype(a)`, we have:
> otherwise, if `e` is an unparenthesized id-expression (...), `decltype(e)` is the type of the entity named by `e`.

So `decltype(a)` is the type of `a`. The type of `a` is however *not* `const char(&)[14]`, but rather `const char*`, due to the following:

§[dcl.type.auto.deduct]¶4:
> If the placeholder is the `auto` type-specifier, the deduced type `T'` replacing `T` is determined using the rules for template argument deduction. Obtain `P` from `T` by replacing the occurrences of `auto` with [...] a new invented type template parameter `U` [...]. Deduce a value for `U` using the rules of template argument deduction from a function call, where `P` is a function template parameter type and the corresponding argument is `e`. [...] `T'` is obtained by substituting the deduced `U` into `P`.

In other words, the type of `a` will be deduced the same way as if we passed "Hello, World!" as a template argument of a function.

§[temp.deduct.call]¶2:
> If `P` is not a reference type:
> - If `A` is an array type, the pointer type produced by the array-to-pointer standard conversion is used in place of `A` for type deduction; [...]
where `P` is a template parameter and `A` is the type of argument.

This means that the type of `a` is the result of array-to-pointer conversion of the type of "Hello, World!" (`const char(&)[14]`) which is `const char*`.