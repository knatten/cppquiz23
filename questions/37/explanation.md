According to §[dcl.type.decltype]¶1 in the standard:

> For an expression `E`, the type denoted by decltype(E) is defined as follows:
> (...)
> — if `E` is an unparenthesized id-expression (...), `decltype(E)` is the type of the entity named by `E`.

The type of `a` is `int`, so the type of `b` is also `int`.