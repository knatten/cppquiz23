`""` is not completely empty, it has a terminating NULL character:

§[lex.string]¶10:

> String literal objects are initialized with the sequence of code unit values corresponding to the *string-literal*'s sequence of *s-chars* (originally from non-raw string literals) and *r-chars* (originally from raw string literals), plus a terminating U+0000 NULL character, (...)

Now what's the type of `""`? §[lex.string]¶1:

> The kind of a *string-literal*, its type, and its associated character encoding (§[lex.charset]) are determined by its encoding prefix and sequence of *s-chars* or *r-chars* as defined by Table 12 where *n* is the number of encoded code units as described below.

Since `""` doesn't have any encoding prefix, according to the Table 12 (§[tab:lex.string.literal]), its type is “array of *n* `const char`”. The only code unit we have is a terminating NULL character, so the size of the array is just 1.

Finally, what does `sizeof` return when applied to an array?

§[expr.sizeof]¶2:

> When applied to an array, the result is the total number of bytes in the array. This implies that the size of an array of *n* elements is *n* times the size of an element.

Our array is 1 element long, so it returns 1 times the size of the element. How big is the element?

§[expr.sizeof]¶1:

> The result of `sizeof` applied to any of the narrow character types is `1`.

§[basic.fundamental]¶7:

> Type `char` is a distinct type that has an implementation-defined choice of “`signed char`” or “`unsigned char`” as its underlying type. The three types `char`, `signed char`, and `unsigned char` are collectively called *ordinary character types*. The ordinary character types and `char8_t` are collectively called *narrow character types*.

So we have one element with size `1`, and the program prints `1`.