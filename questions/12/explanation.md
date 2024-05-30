Since `a` is a static local variable, it is automatically zero-initialized. This would not have happened if we removed the keyword `static`, making it a non-static local variable.

§[basic.start.static]¶2 in the standard:

> If constant initialization is not performed, a variable with static storage duration (6.7.1) or thread storage duration (6.7.2) is zero-initialized (11.6)

`a` has static storage duration and is not constant initialized , so it gets zero-initialized.

§[dcl.init]¶6:

> To zero-initialize an object or reference of type T means:
> — if T is a scalar type (6.9), the object is initialized to the value obtained by converting the integer literal 0 (zero) to T;

So `a` gets initialized to 0.
