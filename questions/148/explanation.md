The issue here is not the missing initializer of the variable `a` - it will implicitly be initialized to `0` since it has static storage duration. The issue is rather that the two accesses of `a` in the expression `a + a` are not sequenced, which leads to undefined behavior.

According to §[intro.execution]¶7, reading the `volatile` `a` is a side effect:
> Reading an object designated by a volatile glvalue, modifying an object, calling a library I/O function, or calling a function that does any of those operations are all *side effects*

And these side effecting reads are unsequenced, which results in undefined behavior. §[intro.execution]¶10:
> Except where noted, evaluations of operands of individual operators and of subexpressions of individual expressions are unsequenced.
> (...)
> If a side effect on a memory location is unsequenced relative to either another side effect on the same memory location or a value computation using the value of any object in the same memory location, and they are not potentially concurrent (§[intro.multithread]), the behavior is undefined.

("Potentially concurrent" is only relevant when there is more than one thread.)