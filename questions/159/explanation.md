According to §[intro.execution]¶11 in the standard, when calling a function:

> every argument expression (...) [is] sequenced before every expression or statement in the body of the called function.

Hence, in the expression `f(i++)`, `f` is called with a parameter of the original value of `i`, but `i` is incremented before entering the body of `f`.
