According to §[dcl.link]¶8 in the standard:

> A declaration directly contained in a *linkage-specification* is treated as if it contains the `extern` specifier (§[dcl.stc]) for the purpose of determining the linkage of the declared name and whether it is a definition. (...)
>
> [*Example 5*:
> ```
> (...)
> extern "C" int i;                   // declaration
> extern "C" {
>   int i;                            // definition
> }
> (...)
> ```
> — *end example*]

And according to §[basic.def.odr]¶11:

> Every program shall contain at least one definition of every function or variable that is odr-used in that program outside of a discarded statement; no diagnostic required.

The result: `x` is never defined but it is optional for the compiler to print an error. The behaviour of this program is undefined.