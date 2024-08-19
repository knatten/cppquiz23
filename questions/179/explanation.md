Modifying a const object results in undefined behavior. Casting away constness does not help.

§[dcl.type.cv]¶4 in the standard:

> Any attempt to modify a `const` object during its lifetime results in undefined behavior.

But we're modifying `r`, not `i`, so §[expr.const.cast]¶4 is also relevant:

> The result of a reference `const_cast` refers to the original object if the operand is a glvalue(...)

`i` is a glvalue, so the result of the `const_cast` refers to `i`.