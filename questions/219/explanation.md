`T sum(T arg, Args... args)` is a function template which calls itself recursively until it hits the base case `T sum(T arg)`. For instance, `sum(a₁, a₂, a₃, a₄)` is implemented as `a₁ + sum(a₂, a₃, a₄)`.

When no `T` is specified, `T` is deduced to be the type of the first argument to `sum`. In the case of `n1`, `T` is deduced to `double` (the type of `0.5`), and in the case of `n2`, `T` is deduced to `int` (the type of `1`).

However, when `sum` calls itself, it explicitly specifies `T` (it does `sum<T>(args...)`). So `T` is only deduced on the initial call to `sum`, and this `T` is used for all the subsequent recursive calls, no matter the type of the arguments along the way.

For `n1`, `T` is always `double`, so `sum` always takes a `double` as the first parameter, and returns a `double`. The sum is `(0.5 + (1 + (0.5 + (1)))) == 3`. (Each set of parentheses denotes a recursive call to `sum`).

For `n2` however, `T` is always `int`, so `sum` always takes an `int` as the first parameter, and returns a `int`, even when we pass `0.5`. What happens when we pass a `double` argument to an `int` parameter? According to §[conv.fpint]¶1 in the C++ standard: 
> A prvalue of a floating point type can be converted to a prvalue of an integer type. The conversion truncates; that is, the fractional part is discarded.

So in the case of `n2`, each time we pass `0.5`, it gets truncated to `0`, and the sum is (1 + (0+ (1 + (0)))) == 2.