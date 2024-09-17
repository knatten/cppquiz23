The `std::exit` function calls the destructors of all objects with static storage duration, but is not responsible for destroying local variables. Therefore, when `std::exit(0);` is called, only the destructor of `a` is called; `b` is a local variable and its destructor is thus not called.

§[support.start.term]¶9.1:

> ```
> [[noreturn]] void exit(int status);
> ```
>
> *Effects*:
>
> — First, objects with thread storage duration and associated with the current thread are destroyed. Next, objects with static storage duration are destroyed and functions registered by calling `atexit` are called. See §[basic.start.term] for the order of destructions and calls. (Objects with automatic storage duration are not destroyed as a result of calling `exit()`.)