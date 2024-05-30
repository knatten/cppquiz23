The question is which of `I`, `J`, and `K` get incremented. This depends both on operator precedence, evaluation order and short-circuiting. All of these are defined in  §[expr.log.or].

First, precedence. Operator precedence is not actually spelled out anywhere, but you can infer from the syntax below that `&&` (_logical-and-expression_) has higher precedence than `||` (_logical-or-expression_). 

> _logical-or-expression_:
>	&nbsp;&nbsp; _logical-and-expression_
>	&nbsp;&nbsp; _logical-or-expression_ || _logical-and-expression_

So `(++I || ++J && ++K)` will be equal to `(++I || (++J && ++K))`.

Next, evaluation order and short-circuiting:

> `||` guarantees left-to-right evaluation; moreover, the second operand is not evaluated if the first operand evaluates to true.

So we first evaluate `++I`, which is `2`. This evaluates to `true`, so the second operand (`++J && ++K`) is never evaluated, and `J` and `K` do not get incremented. 

The result of that entire expression is `true`, and `1` is printed. We then print `I`, `J` and `K`, which now hold `2`, `1` and `1`, respectively.