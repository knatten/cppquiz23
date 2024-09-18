`f()` has a parameter `a` with a default argument which is a call to a lambda. There are two calls to `f()`, and the question is what the value of `a` ends up as in each case.

First: Is the lambda evaluated each time we call `f()`? Yes, according to §[dcl.fct.default]¶9:

> A default argument is evaluated each time the function is called with no argument for the corresponding parameter.

So for each call to `f()`, the lambda is called.

The `static` variable `b` is post-incremented, which means it increments by one, but returns the previous value. So for the first call to `f()`, `b` is initialized to `1`, then `b++` increments it to `2`, while still returning `1`. The `1` is assigned to `a`, and `1` is printed.

For the second call, the lambda is called again, returning a post-incremented `b`. The question is then if this is the same `b` as in the first call (so `2` is returned), or if it's a different `b` (so `1` is returned again).

§[expr.prim.lambda.closure]¶1:

> The type of a *lambda-expression* (which is also the type of the closure object) is a unique, unnamed non-union class type, called the *closure type* (...).

The *lambda-expression* is the expression `[]() { static int b = 1; return b++; }`. A lambda-expression that is evaluated more than once is still the same expression on each evaluation, so it has the same type in each evaluation. This means the `static int b` is the same object for both calls (it's a static local variable in the function call operator of the unique closure type). For the second call, `b` retains the value of `2` from the previous call, which is assigned to `a` and then printed.