When deducing the return type of `sum`,  we need to deduce the type of all return statements and make sure they are the same:  §[dcl.spec.auto]¶8:
> If a function with a declared return type that contains a placeholder type has multiple non-discarded return statements, the return type is deduced for each such return statement. If the type deduced is not the same in each deduction, the program is ill-formed.

For `return i` , we deduce `int`, but what do we deduce from `return sum(i-1)+i`? Can we use the type of `sum` to deduce the type of `sum`? Actually, we don't have to.  §[dcl.spec.auto]¶10:

> If the type of an entity with an undeduced placeholder type is needed to determine the type of an expression, the program is ill-formed. Once a non-discarded return statement has been seen in a function, however, the return type deduced from that statement can be used in the rest of the function, including in other `return` statements. [An example follows which is almost identical to this question]

So we can first deduce `int` from `return i`, and then use that for the rest of the function.

Note that if we were to invert the if statement and swap the order of the return statements like so, we'd get a compilation error, since we haven't deduced `int` from `return i` yet when we encounter the recursive call:


    if (i > 1)
      return sum(i-1)+i;
    else
      return i;