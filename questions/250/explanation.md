The first `foo` (let's call it `foo₁`) is a template for an old-school (pre variadic templates) variadic function. It takes a first argument of type `T`, followed by a varying number of arguments.

The second `foo` (let's call it `foo₂`) is a variadic function template (notice the ellipsis in `typename...`). It takes a parameter pack.

Which overload is selected for each of the calls to `foo`?

When a function is overloaded, we first need to find which of the functions are viable for a given function call. Then, we need to find out which of those viable functions is the best one. For function templates, we first perform template argument deduction to generate candidate specializations.

### `foo(1)`:

First let's look at the call `foo(1)`. The explanation is lengthy, but rest assured we reuse most of it in the much shorter explanation of `foo(1,2)`! 

We start by deducing the template arguments for both overloads. For `foo₁`, the argument `1` is used to deduce `T` to be `int`. It's signature is then `foo₁(int, ...)`. However, for overload resolution we ignore the `...` since it doesn't have a matching argument: §[over.match.viable]¶2.3:

> For the purposes of overload resolution, the parameter list is truncated on the right, so that there are exactly *m* parameters.

So we end up with the viable function `foo₁(int)`.

For `foo₂`, `T...` is a function parameter pack. The argument `1`  is used to deduce this as one `int`, and it's signature is `foo₂(int)`.

So, both `foo`s are viable. Which one is best? §[over.match.best]¶2:

> (...) a viable function `F1` is defined to be a better function than another viable function `F2` if (...)

§[over.match.best.general]¶2.5:

> — `F1` and `F2` are function template specializations, and the function template for `F1` is more specialized than the template for `F2` according to the partial ordering rules described in §[temp.func.order] (...)

I won't go into all the details for partial ordering here, but skip to the interesting parts. In short, we transform each specialization by substituting each template parameter with a unique, made-up type and get `foo₁(X, ...)` and `foo₂(Y)`. Then we do deduction from each transformed function to the other, original template.

Again, the ellipsis is ignored since it doesn't have an argument at the call site: §[temp.deduct.partial]¶3:

> The types used to determine the ordering depend on the context in which the partial ordering is done:
> - In the context of a function call, the types used are those function parameter types for which the function call has arguments.

We now do deduction of  `foo₂(T...)` from `foo₁(X)`, which deduces `T=X`.

We then do deduction of `foo₁(T)` from `foo₂(Y)`. It looks like we would get `T=Y`, but §[temp.deduct.type]¶9.2 says:

> During partial ordering, if `A`<sub>*i*</sub> was originally a pack expansion:
>
> — (...) if `P`<sub>*i*</sub> is not a pack expansion, template argument deduction fails.

`A`<sub>*i*</sub> in this case is `Y`, which was originally a function parameter pack. `P`<sub>*i*</sub> is `T`, which is not a function parameter pack, so deduction fails.

Since we can deduce `foo₂` from `foo₁`, but not `foo₁` from `foo₂`, `foo₁` is more specialized and a better function. Overload resolution picks it and prints `A`.

### `foo(1,2)`:

Now let's look at the call `foo(1,2)`.

Again we start by deducing the template arguments. For `foo₁`, the first argument `1` is used to deduce `T` to be `int`. Its signature is then `foo₁(int, ...)`.

For `foo₂`, `T...` is a function parameter pack. The arguments `1` and `2` are used to deduce this as two `int`s, and its signature is `foo₂(int, int)`.

Which of these is the best match? We turn to §[over.match.best.general]¶2.1 which checks whether for some argument of a function call there exists a better implicit conversion sequence from this argument to the corresponding parameter in the other function call.

For both templates, the first argument is an exact match. For `foo₁`, the second argument `2` requires an ellipsis conversion sequence to match the second parameter `...`: §[over.ics.ellipsis]¶1:

> An ellipsis conversion sequence occurs when an argument in a function call is matched with the ellipsis parameter specification of the function called

For `foo₂`, no conversion is required, so it's a better match. The second `foo` is called, and `B` is printed.