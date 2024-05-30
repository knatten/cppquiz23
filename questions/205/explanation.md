`array` is an array of `unsigned char`, but is initialized with `unsigned int`s. The `unsigned int`s have to be converted to `unsigned char`s, so we might expect a narrowing diagnostic. §[dcl.init.aggr]¶3 in the standard says:

> (...) If the initializer-clause is an expression and **a narrowing conversion (§11.6.4) is required to convert the expression, the program is ill-formed**. (...)

§[dcl.init.list].k.4¶7 tells us what a narrowing conversion is:

>A narrowing conversion is an implicit conversion (...) from an integer type (...) to an integer type that cannot represent all the values of the original type

An `unsigned char` cannot represent all the values of an `unsigned int`, so we would normally expect a diagnostic. However, the above clause continues with an exception for the case where the source is a *constant expression* whose value after promotion fits in the target type:

> except where the source is a constant expression whose value after integral promotions will fit into the target type.

So since `id` is `constexpr`, and both `id % 3` and `id % 5` fits in an `unsigned char`, the program is well-formed.