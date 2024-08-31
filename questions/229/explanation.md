Only local variables may be captured by a lambda. `a` is a global variable with static storage duration and may not be captured. §[expr.prim.lambda.capture]¶1:

> The body of a *lambda-expression* may refer to local entities of enclosing block scopes by capturing those entities (...).

Since `a` is not captured, `a` in the lambda expression simply refers to the global variable `a`.