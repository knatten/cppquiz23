`array` is an array of `unsigned char`, but is initialized with `unsigned int`s. The `unsigned int`s have to be converted to `unsigned char`s, and since narrowing is not allowed in aggregate-initialization from an initializer list, we might expect a compilation error.

§[dcl.init.aggr]¶3:

> When an aggregate is initialized by an initializer list as specified in §[dcl.init.list], the elements of the initializer list are taken as initializers for the elements of the aggregate.

And §[dcl.init.aggr]¶4:

> For each explicitly initialized element (...) [if] a narrowing conversion §[dcl.init.list] is required to convert the expression, the program is ill-formed.

§[dcl.init.list]¶7 tells us what a narrowing conversion is:

> A narrowing conversion is an implicit conversion (...) from an integer type (...) to an integer type that cannot represent all the values of the original type

An `unsigned char` cannot represent all the values of an `unsigned int`, so we would normally expect a diagnostic. However, the above clause continues with an exception for the case where the source is a *constant expression* whose value after promotion fits in the target type:

> except where the source is a constant expression whose value after integral promotions will fit into the target type.

So since `id` is `constexpr`, and both `id % 3` and `id % 5` fit in an `unsigned char`, the program is well-formed.