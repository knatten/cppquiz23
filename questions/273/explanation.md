First, the program unsurprisingly prints `main`. But what happens on the next line?

§[expr.sizeof]¶1 in the standard:

> The `sizeof` operator yields the number of bytes occupied by a non-potentially-overlapping object of the type of its operand. The operand is either an expression, which is an unevaluated operand, or a parenthesized *type-id*.

The most common form of `sizeof` is probably the latter, `sizeof(type-id)` (e.g. `sizeof(int)`). But there's also the `sizeof expression` form (e.g. `sizeof new A`) which is used in this question.

The operand here is the expression `new A`. The type of that expression is "pointer to `A`". The size of a pointer varies between platforms, but that doesn't really matter in this question since we never print it. The question is whether `new A` constructs a new `A`, and if so, whether it gets destructed.

The quote above says that the expression is "an unevaluated operand", but what does that mean?

§[expr.context]¶1:

> In some contexts, *unevaluated operands* appear (§[expr.prim.req], §[expr.typeid], §[expr.sizeof], §[expr.unary.noexcept], §[dcl.type.decltype], §[temp.pre], §[temp.concept]). An unevaluated operand is not evaluated.

So the expression `new A` is not evaluated, and `A` is never constructed. The expression is only used for `sizeof`.

(And since there is no `delete`, `A` is never destructed either.)