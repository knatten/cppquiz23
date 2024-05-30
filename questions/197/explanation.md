There are two variables named `j` here. The first is the global one, the second is local to `main`. A variable is in scope from the point of its declaration until the end of the region in which it was declared, except for when another variable with the same name is in scope. 

It's easiest to first look at the scope of the local `j` declared inside `main`, which extends from the `,` to the `}`. The scope of the global `j` is from when it was declared until the end of the program, except for when the local `j` is in scope.

So the reference `i` refers to the *global* `j`, since the local `j` is not yet in scope. When we set `j=2`, we modify the *local* `j`, and `i` is not affected.

This example is almost identical to §[basic.scope.declarative]¶2 in the C++ standard, which has the following explanation:

> the identifier `j` is declared twice as a name (and used twice). The declarative region of the first `j` includes the entire example. The potential scope of the first `j` begins immediately after that `j` and extends to the end of the program, but its (actual) scope excludes the text between the `,` and the `}`. The declarative region of the second declaration of `j` (the `j` immediately before the semicolon) includes all the text between `{` and `}`, but its potential scope excludes the declaration of `i`. The scope of the second declaration of `j` is the same as its potential scope.