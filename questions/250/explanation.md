The first `foo` (let's call it `foo₁`) is a template for an old-school (pre variadic templates) variadic function. It takes a first argument of type `T`, followed by a varying number of arguments.

The second `foo` (let's call it `foo₂`) is a variadic function template (notice the ellipsis in `typename...`). It takes a parameter pack.

Which overload is selected for each of the calls to `foo`?

When a function is overloaded, we first need to find which of the functions are viable for a given function call. Then, we need to find out which of those viable functions is the best one. For function templates, we first perform template argument deduction to generate candidate specializations.

### `foo(1)`:

First let's look at the call `foo(1)`. The explanation is lengthy, but rest assured we reuse most of it in the much shorter explanation of `foo(1,2)`! 

We start by deducing the template arguments for both overloads. For `foo₁`, the argument `1` is used to deduce `T` to be `int`. Its signature is then `foo₁(int, ...)`. Is it viable? §[over.match.viable]¶2.1:

> — If there are `m` arguments in the list, all candidate functions having exactly `m` parameters are viable.

But don't we have 2 parameters and 1 argument? It turns out an ellipsis is not considered to be a parameter in this context since it's not included in the *parameter-declaration-list* grammar production (§[dcl.fct]¶nt:parameter-declaration-list).

`1` is already an `int`, matching the parameter type `int`, so `foo₁` is viable.

For `foo₂`, `T...` is a function parameter pack. The argument `1` is used to deduce this as one `int`, and its signature is `foo₂(int)`. The same reasoning as above applies, concluding that `foo₂` is viable.

So, both `foo`s are viable. Which one is best? §[over.match.best.general]¶2:

> (...) a viable function `F1` is defined to be a better function than another viable function `F2` if (...)

§[over.match.best.general]¶2.5:

> — `F1` and `F2` are function template specializations, and the function template for `F1` is more specialized than the template for `F2` according to the partial ordering rules described in §[temp.func.order] (...)

We won't go into all the details for partial ordering here, but skip to the interesting parts. In short, we transform each specialization by substituting each template parameter with a unique, made-up type and get `foo₁(X, ...)` and `foo₂(Y)`.
We now do deduction of `foo₂(T...)` from `foo₁(X)`, which deduces `T=X`. We then do deduction of `foo₁(T)` from `foo₂(Y)`. It looks like we would get `T=Y`, but §[temp.deduct.type]¶9.2 says:

> During partial ordering, if `A`<sub>*i*</sub> was originally a pack expansion:
>
> — (...) if `P`<sub>*i*</sub> is not a pack expansion, template argument deduction fails.

`A`<sub>*i*</sub> in this case is `Y`, which was originally a function parameter pack. `P`<sub>*i*</sub> is `T`, which is not a function parameter pack, so deduction fails.

Since we can deduce `foo₂` from `foo₁`, but not `foo₁` from `foo₂`, `foo₁` is more specialized and a better function. Overload resolution picks it and prints `A`.

### `foo(1,2)`:

Now let's look at the call `foo(1,2)`.

Again we start by deducing the template arguments. For `foo₁`, the first argument `1` is used to deduce `T` to be `int`. Its signature is then `foo₁(int, ...)`.

For `foo₂`, `T...` is a function parameter pack. The arguments `1` and `2` are used to deduce this as two `int`s, and its signature is `foo₂(int, int)`.

`foo₂` is viable for the same reasons as before, `foo₁` is viable due to §[over.match.viable]¶2.2:

> A candidate function having fewer than `m` parameters is viable only if it has an ellipsis in its parameter list (§[dcl.fct]). For the purposes of overload resolution, any argument for which there is no corresponding parameter is considered to “match the ellipsis” (§[over.ics.ellipsis]).

Which of these is the best match? We turn to §[over.match.best.general]¶2.1 which checks whether for some argument of a function call there exists a better implicit conversion sequence from this argument to the corresponding parameter in the other function call.

For both templates, the first argument is an exact match. For `foo₁`, the second argument `2` requires an ellipsis conversion sequence to match the ellipsis parameter specification `...`: §[over.ics.ellipsis]¶1:

> An ellipsis conversion sequence occurs when an argument in a function call is matched with the ellipsis parameter specification of the function called (see [§expr.call]).

For `foo₂`, no conversion is required, so it's a better match. The second `foo` is called, and `B` is printed.