The main question here is about the evaluation order of the two `++i` expressions, which initialize the two parameters `x` and `y` to `print`. `print` takes these by value, so a copy is made for each argument.

Two questions remain: In which order are the two `++i` expressions evaluated to initialize the parameters, and when do the increments of `i` take effect?

First of all, the evaluation order of the two `++i` expressions is unspecified. §[expr.call]¶7:
>  The initialization of a parameter, including every associated value computation and side effect, is indeterminately sequenced with respect to that of any other parameter.

What does "indeterminately sequenced" mean?

§[intro.execution]¶8:
> Evaluations A and B are indeterminately sequenced when either A is sequenced before B or B is sequenced before A, but it is unspecified which.

So from the two quotes above we see that they can happen in either order, and importantly that all side effects of the first evaluation (whichever that might be) are guaranteed to be completed before the second one gets evaluated.

Let's say the implementation decides to go left to right. Then the first parameter `x` is initialized by the leftmost expression `++i`, which increments `i` and results in the updated `i` which is now `1`. Next, the second parameter `y` is initialized by the rightmost expression `++i`, which increments `i` and results in the updated `i` which is now `2`. Then, `print` prints `12`.

Alternatively, the implementation could decide to go right to left, and `print` would print `21`.

So this is unspecified (but not undefined) behavior, and a conforming implementation can either print `12` or `21`, but not for instance `22`. Interestingly, `22` is what GCC prints at the time of writing, and there's an [open bug](https://gcc.gnu.org/bugzilla/show_bug.cgi?id=78734) for that.
