§[basic.start.dynamic]¶5 in the standard:

> It is implementation-defined whether the dynamic initialization of a non-block non-inline variable with static storage duration is sequenced before the first statement of main or is deferred. If it is deferred, it strongly happens before any non-initialization odr-use of any non-inline function or non-inline variable defined in the same translation unit as the variable to be initialized.

Since `A()` is not `constexpr`, the initialization of `a` is dynamic. There are two possibilities:
- `a` is initialized before `main()` is called.
- The initialization of `a` is deferred, but it is initialized before any non-inline function in the same translation unit as it is used. And since `main()` and `a` are defined in the same translation unit, it is still initialized before `main()`.

When execution reaches `B b`, it is initialized as normal. Static local variables are initialized the first time control passes through their declaration, so `c` is initialized next. As `main()` is exited, its local variable `b` goes out of scope, and is destroyed. Finally, all static variables are destroyed in reverse order of their initialization, first `c`, then `a`.