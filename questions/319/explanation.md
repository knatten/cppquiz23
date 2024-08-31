What is the return type of the lambda function `L`?

It is inferred from the type of the operand of its return statement.

So it's the type of the conditional operator `?:`, which is specified in §[expr.cond]¶4:

> Otherwise, if the second and third operand have different types and either has (possibly cv-qualified) class type, (...) an attempt is made to form an implicit conversion sequence from each of those operands to the type of the other.

The implicit conversion sequence is provided by the `B(const A&)` constructor of `B`.

§[class.conv.ctor]¶1:

> A constructor that is not explicit (§[dcl.fct.spec]) specifies a conversion from the types of its parameters (if any) to the type of its class. Such a constructor is called a *converting constructor*.

Hence, the return type of the lambda `L` is always `B`.
In the first case, when `flag` is true, it returns a `B` object constructed from a temporary `A`.