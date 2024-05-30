§[basic.start.dynamic]¶5 in the standard:
"It is implementation-defined whether the dynamic initialization of a non-local inline variable with static storage duration is sequenced before the first statement of main or is deferred. If it is deferred, it strongly happens before any non-initialization odr-use of that variable."

Since `A()` is not `constexpr`, the initialization of `a` is dynamic. There are two possibilities:
- `a` is initialized before `main()` is called, i.e. before `c` or `b` are initialized.
- `a` is **not** initialized before `main()`. It is however guaranteed to be initialized before the the use of any function defined in the same translation unit, i.e. before the constructors of `c` and `b` are called.

Then, `c` and `b` are initialized in order.

Before `main()` exits, `b` and `c` are destructed in the reverse order of their construction. Then, when `main()` returns, `a` is destructed as per §[basic.start.term] in the standard:
"Destructors for initialized objects (...) with static storage duration are called as a result of returning from main."