Due to the `extern "C"` specifications, `A::x` and `B::x` actually refer to the same variable.

`x` is first initialized to `0`, then `main()` starts, `0` is printed, `x` is incremented to `1`, and finally `1` is printed.

§[dcl.link]¶7 in the C++23 standard:
"Two declarations declare the same entity if they (re)introduce the same name, ..."
