The function template `f` is only ever instantiated for `int`. In this case, the `if constexpr` is `true`, and the function returns `0`. The `{ return std::string{} }` statement is a discarded statement. So is this ok then? It is not ok, and in fact it is undefined behaviour!

§[temp.res.general]¶6.4:

> The program is ill-formed, no diagnostic required, if:
>
> — (...)
>
> — a hypothetical instantiation of a template immediately following its definition would be ill-formed due to a construct that does not depend on a template parameter

In any hypothetical instantiation of `f`, `std::string{}` does not depend on the template parameter, and the instantiation would be ill-formed. So the program is ill-formed, no diagnostic required, aka. undefined behaviour.

At the time of writing, GCC and Clang give a compilation error complaining they can't convert `std::string` to `int`, whereas MSVC prints `0`.