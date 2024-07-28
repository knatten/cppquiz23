First, let's have a look at the initialization of `X::Var`. `Var(0, args...)` is valid if there are no template arguments, since then it's just `Var(0)`. If there however are any template arguments, they expand to an invalid initializer for `int`, such as `Var(0, arg1, arg2)`. So the only valid specialization of `X` is the one with no arguments.

`X<> x` in fact does just that, it instantiates the template with no arguments, which would be valid.

However, §[temp.res.general]¶6.3 says:

> The program is ill-formed, no diagnostic required, if:
>
> — (...)
>
> — every valid specialization of a variadic template requires an empty template parameter pack, (...)

As we've seen, the only valid specialization requires an empty template parameter pack, so the program is ill-formed, no diagnostic required. When no diagnostic is required, the compiler is not required to diagnose the error, but execution of the program is undefined.