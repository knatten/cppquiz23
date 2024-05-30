For both `a1 + a2` and `a1 == a2`, the built-in operators `operator+` and `operator==` for `int` is used. The two objects `a1` and `a2` are implicitly converted first to `bool` and then to `int` before calling the operator. In both cases, they convert first to `true`, then to `1`.

`1 + 1`  equals `2`, and `1 == 1` is true, so `21` is printed.

##### Detailed explanation:
We'll go through the full reasoning for `operator+` first:

`struct A` does not overload `operator+`, so we need to use a built-in `operator+`. Can we somehow convert `a1` and `a2` to a type compatible with `operator+`?

§[conv]¶2: 
> expressions with a given type will be implicitly converted to other types in several contexts:
> — When used as operands of operators
> (...)

So we are allowed to use an implicit conversion sequence to convert `a1` and `a2` into something we can use with a built in `operator+`. The specific type of implicit conversion sequence we need in this case is a user-defined conversion sequence, which is defined in  §[over.ics.user]¶1:
>A user-defined conversion sequence consists of an initial standard conversion sequence followed by a user-defined conversion (12.3) followed by a second standard conversion sequence.

As a first try, can we use the user-defined conversion to `bool` (our `operator bool() const`) and then use an `operator+` for `bool`? §[over.built]¶9:
> For every promoted arithmetic type `T` , there exist candidate operator functions of the form
> `T operator+(T);`

And what's a promoted arithmetic type? §[over.built]¶2:
> the term promoted integral type is used to refer to those integral types which are preserved by integral promotion [...]. Similarly, the term promoted arithmetic type refers to floating types plus promoted integral types.

So is bool a promoted arithmetic type? It's certainly not a floating type, but is it a promoted integral type? No, §[conv.prom]¶6:
> A prvalue of type `bool` can be converted to a prvalue of type `int`, with `false` becoming zero and `true` becoming one.

So `operator+` does not exist for `bool`, and we have to continue with our implicit conversion sequence. After the user-defined conversion from `A` to `bool`, we can use a standard conversion sequence, in particular the integral promotion we just discussed,  converting `true` to `1`. We then call `operator+` for `int`, with the operands `1` and `1`, resulting in `2`.

For `operator==`, the story is exactly the same, as §[over.built]¶13 says:
> For every pair of promoted arithmetic types L and R , there exist candidate operator functions of the form (...)
> `bool operator==(L, R);`

So we use the same conversion sequence from `A` to `bool` to `int`, ending up comparing `1` to `1`, which results in `true`.