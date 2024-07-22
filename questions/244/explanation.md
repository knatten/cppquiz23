Since C++23, this construct is legal and the code prints `1`.

Before [P2593](https://wg21.link/p2593), the §[temp.res.general]¶6.1 clause didn't contain an exception for `static_assert`s:

> The program is ill-formed, no diagnostic required, if:
>
> — no valid specialization, ignoring *static_assert-declaration*s that fail, can be generated for a template or a substatement of a constexpr if statement within a template and the template is not instantiated (...)

So our program was ill-formed, no diagnostic required, and we had undefined behaviour.
This was causing complications when writing useful compile-time checks prior to C++23.
As a result, the behaviour was changed, and now the mere presence of such a declaration in a template definition has no effect (as opposed to actually instantiating the template), and the program is well-formed. §[dcl.pre]¶10:

> In a *static_assert-declaration*, the *constant-expression* is contextually converted to `bool` and the converted expression shall be a constant expression (§[expr.const]). If the value of the expression when so converted is `true` or the expression is evaluated in the context of a template definition, the declaration has no effect.