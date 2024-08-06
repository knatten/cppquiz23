§[class.temporary]¶4 in the standard:

> Temporary objects are destroyed as the last step in evaluating the full-expression (§[intro.execution]) that (lexically) contains the point where they were created.

This means that normally the temporaries returned from `C(1)`, `C(2)`, and `C(3)` should be destroyed at the end of the line.

However, §[class.temporary]¶6 states:

> The temporary object to which the reference is bound (...) persists for the lifetime of the reference (...)

, so the lifetime of the temporary returned by `C(1)` is extended for the lifetime of `c`, to the end of `main()`. The temporaries returned by `C(2)` and `C(3)` are still destroyed at the end of their lines of creation, so they get destroyed before the one returned by `C(1)`.