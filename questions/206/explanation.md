We have several pieces of the puzzle, so let's peel away the layers.

The grammar for `sizeof` is in §[expr.unary]¶8.3:

> unary-expression:
> ...
> sizeof unary-expression
> sizeof ( type-id )
> sizeof ... ( identifier )
> ...

We have three cases and the one that applies here is **sizeof unary-expression**. The *unary expression* is `(0)["abcdefghij"]`, which looks odd but is just array indexing of *string literal* which is a *const char array*. 

We can see that `(0)["abcdefghij"]` is identical to `("abcdefghij")[0]` from §[expr.sub]¶8.2.1 which says:

> ... The expression `E1[E2]` is identical (by definition) to `*((E1)+(E2))` ...

So we end up with 0th element of `"abcdefghij"`, which is `a`, which is a `char`. And the result of `sizeof('a')` will be `1` since §[expr.sizeof]¶8.3.3 says:

> ... `sizeof(char)`, `sizeof(signed char)` and `sizeof(unsigned char)` are `1` ...
