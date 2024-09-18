The line `int& i = j, j;` declares two variables `i` and `j`. (If this is surprising, remember that you can declare multiple variables at once, e.g. `int i, j, k;`. `i` here just happens to have an initializer.)

So this program has two variables named `j`. The first is the global one, the second is local to `main`. Which one is used to initialize `i` in the expression `int& i = j`?

When initializing `i` with the expression `j`, we need to do name lookup for `j`. If the local `j` is in scope at that point in the program, it will be used, otherwise, the global `j` will be used.

§[basic.scope.pdecl]¶1:

> The *locus* of a declaration (§[basic.pre]) that is a declarator is immediately after the complete declarator (§[dcl.decl]).

So the *locus* of the local `j` is here:
```
int& i = j, j;
            /\
```

And §[basic.lookup.general]¶2 says:

> A program point *P* is said to follow any declaration in the same translation unit whose locus (§[basic.scope.pdecl]) is before *P*.

The locus of the local `j` is *after* the program point *P* where the reference `i` is bound, so *P* does not follow the declaration of the local `j`.

This means that name lookup for `j` in the expression `int& i = j` does not find the local `j`, but rather the global `j`, and `i` is bound to the global `j`.

However, the program point where we set `j = 2` does follow the locus of the local `j`, so we modify the *local* `j`, and the `j` that `i` refers to is not affected.