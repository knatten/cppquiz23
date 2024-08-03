The evaluation order of function argument expressions is unspecified, all we know is that they will all happen before ("be sequenced before") the contents of the called function.

In particular, in the expression `g(f1(), f2())`,  we don't know whether `f1` or `f2` will be sequenced first, we only know that they will both be sequenced before the body of `g`.

Also: There isn't even a requirement on the implementation that `f1` and `f2` gets evaluated *in the same order each time*. So after calling `h` twice, `v` can contain `1212`, `2121`, `1221` or `2112`.

§[expr.call]¶7:
> The initialization of a parameter, including every associated value computation and side effect, is indeterminately sequenced with respect to that of any other parameter.

And the helpful note in §[intro.executation]¶note-5:

> In an expression that is evaluated more than once during the execution of a program, unsequenced and indeterminately sequenced evaluations of its subexpressions need not be performed consistently in different evaluations.