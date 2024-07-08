Due to the `extern "C"` specifications, `A::x` and `B::x` actually refer to the same variable.

`x` is first initialized to `0`, then `main()` starts, `0` is printed, `x` is incremented to `1`, and finally `1` is printed.

§[dcl.link]¶7 in the C++ standard:

> Two declarations declare the same entity if they (re)introduce the same name, one declares a function or variable with C language linkage, and the other declares such an entity or declares a variable that belongs to the global scope.
