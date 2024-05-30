`f()` evaluates to false, so the value of the whole conditional expression is the value of the third expression `h()`, that is the character `h`. But which functions are evaluated, and in which order?

Let's have a look at §[expr.cond]¶1 in the standard:
"Every value computation and side effect associated with the first expression is sequenced before every value computation and side effect associated with the second or third expression."

This means that `f()` completes before `g()` or `h()`, and `f` is the first thing to get printed.

The second question is whether both `g()` and `h()` are called before the resulting value is selected, or if only one of them are. Again, §[expr.cond]¶1 has the answer:
"Only one of the second and third expressions is evaluated."
Since `f()` evaluated to false, `h()` is selected, `h()`, and `h` is printed. `g()` is never called.

Finally, on the last line, the value of `result`, `h` is printed.