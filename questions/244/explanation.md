Normally, `static_assert(false)` causes compilation to fail. But in this case, it's contained inside a template which is never instantiated. Is the compiler then supposed to ignore it, or report an error?

§[temp.inst]¶8:
> The program is ill-formed, no diagnostic required, if:
>[...]
> a hypothetical instantiation of a template immediately following its definition would be ill-formed due to a construct that does not depend on a template parameter

The `static_assert(false)` does not depend on a template parameter, so if we were to instantiate `A`  immediately following its definition, `A` would always be ill-formed.

So our program is ill-formed, no diagnostic required, and we have undefined behaviour. 

Note: At the time of writing, the latest gcc, clang and msvc all give a compilation error for this example.