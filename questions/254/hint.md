`is_same_v<T, U>` is `true` if `T` and `U` are the same type, false otherwise.

In the first case, we're checking whether a function taking an `int` has the same type as a function taking a `const int`.

In the second case, we're checking whether a function taking a pointer to `int` has the same type as a function taking a pointer to `const int` (note that it's a *pointer to `const`*, not a *`const` pointer*.)