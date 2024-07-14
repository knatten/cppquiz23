`c` is an lvalue `char`. `&c` returns a pointer to the lvalue `c`, but that pointer itself is an rvalue, since it's just a nameless temporary returned from `operator&`. §[expr.unary.op]¶3:

> The operand of the unary `&` operator shall be an lvalue of some type T. The result is a prvalue.

The first overload of `f` takes an rvalue reference to `char *`, the second takes an lvalue reference to `char*`. Since the pointer is an rvalue, the first overload is selected, and `1` is printed.