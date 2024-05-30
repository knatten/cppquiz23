`C.i` is a reference. When we assign something to a reference variable, we don't change that variable to refer to something else, we modify whatever it's referring to.

So `c.i = y` doesn't modify `c` to refer to `y` instead of `x`, it assigns the value of `y` to what `c.i` is referring to. `c.i` is referring to `x`, so the value of `y` is assigned to `x`.

When we print the values on the last line, both `x` and `y` are `2`, and since `c.x` still refers to `x`, that also prints `2`.