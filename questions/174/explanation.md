Both `a` and `b` refer to the same variable `x`.

The fact that `b` is a `const` reference does not guarantee that `b` isn't modified from elsewhere, only that **we** can't modify it.