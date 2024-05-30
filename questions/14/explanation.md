§[basic.start.dynamic]¶4 in the standard:
"It is implementation-defined whether the dynamic initialization of a non-local non-inline variable with static storage duration is sequenced before the first statement of main or is deferred. If it is deferred, it strongly happens before any non-initialization odr-use of any non-inline function or non-inline variable defined in the same translation unit as the variable to be initialized."

Since `A()` is not `constexpr`, the initialization of `a` is dynamic. There are two possibilities:
- `a` is initialized before `main()` is called, i.e. before `b` is initialized.
- `a` is **not** initialized before `main()`. It is however guaranteed to be initialized before the the use of any function defined in the same translation unit, i.e. before the constructor of `b` is called.

When execution reaches `B b`, it is initialized as normal. Static local variables are initialized the first time control passes through their declaration, so `c` is initialized next. As `main()` is exited, its local variable `b` goes out of scope, and is destroyed. Finally, all static variables are destroyed in reverse order of their initialization, first `c`, then `a`.
