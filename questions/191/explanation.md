Due to the `extern "C"` specifications, `A::x` and `B::x` actually refer to the same variable.

`x` is first initialized to `0`, then `main()` starts, `0` is printed, `x` is incremented to `1`, and finally `1` is printed.

§[dcl.link]¶6 in the C++ standard:
"Two declarations for a variable with C language linkage with the same name (ignoring the namespace names that qualify it) that appear in different namespace scopes refer to the same variable."
