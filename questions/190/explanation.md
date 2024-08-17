For both `a1 + a2` and `a1 == a2`, the built-in operators `operator+` and `operator==` for `int` are used. The two objects `a1` and `a2` are implicitly converted first to `bool` and then to `int` before calling the operator. In both cases, they convert first to `true`, then to `1`.

`1 + 1`  equals `2`, and `1 == 1` is true, so `21` is printed.

##### Detailed explanation:

We'll go through the full reasoning for `operator+` first:

`struct A` does not overload `operator+`, so we need to use a built-in `operator+`. Can we somehow convert `a1` and `a2` to a type compatible with `operator+`? §[over.best.ics.general]¶1:

> An *implicit conversion sequence* is a sequence of conversions used to convert an argument in a function call to the type of the corresponding parameter of the function being called.

§[over.best.ics.general]¶3 goes further:

> A well-formed implicit conversion sequence is one of the following forms:
>
> — a standard conversion sequence,
>
> — a user-defined conversion sequence, or
>
> — an ellipsis conversion sequence.

In our case, a single standard conversion sequence is not enough, we don't have an ellipsis parameter, and the exceptions from §[over.best.ics.general]¶4 don't apply either. So we continue with a user-defined conversion sequence. §[over.ics.user]¶1:

> A *user-defined conversion sequence* consists of an initial standard conversion sequence followed by a user-defined conversion (§[class.conv]) followed by a second standard conversion sequence.

Let's go over these three conversions one by one. First, §[over.ics.user]¶1:

> If the user-defined conversion is specified by a conversion function, the initial standard conversion sequence converts the source type to the type of the object parameter of that conversion function.

A standard conversion sequence is a sequence of standard conversions (§[conv.general]¶1). In our case, the initial sequence is empty, since we can directly bind an implicit object parameter, which is an lvalue reference to `const A`, to an lvalue argument of type `A` (§[dcl.init.ref]¶5.1.1).

Then, we use the user-defined conversion specified by the conversion function `operator bool() const` to convert the result to `bool` (§[class.conv.fct]).

Finally, §[over.ics.user]¶2:

> The second standard conversion sequence converts the result of the user-defined conversion to the target type for the sequence (...).

And what is the target type of the conversion in our case? Can we use an `operator+` for `bool` directly? §[over.built]¶10:

> For every pair of types *L* and *R*, where each of *L* and *R* is a floating-point or promoted integral type, there exist candidate operator functions of the form
>
> (...)
>
> ```
> LR      operator+(L, R);
> ```
>
> (...)
>
> where *LR* is the result of the usual arithmetic conversions (§[expr.arith.conv]) between types *L* and *R*.

`bool` is certainly not a floating-point type, but is it a promoted integral type? §[over.built]¶2:

> In this subclause, the term *promoted integral type* is used to refer to those cv-unqualified integral types which are preserved by integral promotion (including e.g. `int` and `long` but excluding e.g. `char`).

But `bool` is not preserved by the promotion. §[conv.prom]¶6:

> A prvalue of type `bool` can be converted to a prvalue of type `int`, with `false` becoming zero and `true` becoming one.

So the second standard conversion sequence is not empty and consists of the integral promotion we just discussed, converting `true` to `1`.

We then call `operator+` for `int`, with the operands `1` and `1`, resulting in `2`.

For `operator==`, the story is exactly the same, as §[over.built]¶10 also requires the parameters of `bool operator==(L, R)` to be of floating-point or promoted integral types.

So we use the same implicit conversion sequence from `A` to `bool` to `int`, ending up comparing `1` to `1`, which results in `true`.