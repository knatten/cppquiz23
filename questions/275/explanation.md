The sizes of the standard integer types are not fixed by the standard. It's perfectly legal to, for instance, have an implementation where both `long` and `int` are 32 bits.

What *do* we know about the sizes of `long` and `int` though?

§[basic.fundamental]¶1 in the standard:

> There are five *standard signed integer types*: “`signed char`”, “`short int`”, “`int`”, “`long int`”, and “`long long int`”. In this list, each type provides at least as much storage as those preceding it in the list.

So we know that `long` is at least as big as `int`. But how big is an int? §[basic.fundamental]¶4:

> The width of each signed integer type shall not be less than the values specified in Table 14. The value representation of a signed or unsigned integer type comprises *N* bits, where *N* is the respective width.
>
> (...)
>
> Except as specified above, the width of a signed or unsigned integer type is implementation-defined.

According to the Table 14 (§[tab:basic.fundamental.width]), `int` has to be at least 16 bits and `long` has to be at least 32 bits. But it's perfectly legal for them both to be 32 bits.