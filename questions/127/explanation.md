The meaning of `decltype(E)` depends on whether `E` itself also is parenthesized. So `decltype(T)` and `decltype((T))` has different meanings. The first (which we don't see in this question) is intended to find the type of a particular identifier. The other, which we see in this question, is intended to find the type of an arbitrary expression.

§[dcl.type.decltype]¶1 in the standard:

> — if E is an unparenthesized id-expression naming a structured binding (...)
> — otherwise, if E is an unparenthesized id-expression naming a non-type template-parameter (...)
> — otherwise, if E is an unparenthesized id-expression or an unparenthesized class member access (...)
> — otherwise, if E is an xvalue, decltype(E) is T&&, where T is the type of E;
> — otherwise, if E is an lvalue, decltype(E) is T&, where T is the type of E;
> — otherwise, decltype(E) is the type of E.

All the examples in this question are parenthesized, so we only need to look at the latter three bullet points. Also, since the type of `(expression)` is the same as the type of `expression`, we can ignore the extra parentheses.

Inside the lambda, the expression `j` is transformed into an access to a member of the closure type which captured the original `j`. According to §[expr.prim.lambda.capture]¶10, the type of that member is `int`:

> The type of such a data member is the referenced type if the entity is a reference to an object

So the expression `j` here is an access to a class member, and we didn't `std::move` from it, so it is an lvalue. Bullet point 5 above applies: "`decltype(E)` is `T&`, where `T` is the type of `E`".

But what's the type of the expression `j`? To figure that out, we need to know whether the function call operator of the closure type is `const` or not. §[expr.prim.lambda.closure]¶5:

> it is a non-static member function or member function template that is declared const if and only if the lambda-expression’s parameter-declaration-clause is not followed by `mutable`

So we're accessing a class member from a `const` member function, which means that `T` above is `const int`, and `decltype(E)` is `const int&`. `00100` is printed.

(Note that at the time of writing, MSVC erroneously prints `01000` instead. GCC had the same issue until version 14. This has caused several erroneous bug reports to cppquiz, such as [this one](https://github.com/knatten/cppquiz/issues/96).)