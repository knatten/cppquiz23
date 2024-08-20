Will the global `foo` or the member `foo` be chosen?

First, notice that the name `foo` is unqualified. §[basic.lookup.unqual]¶4:

> An *unqualified name* is a name that does not immediately follow a *nested-name-specifier* or the `.` or `->` in a class member access expression (§[expr.ref]), possibly after a `template` keyword or `~`. Unless otherwise specified, such a name undergoes unqualified name lookup from the point where it appears.

What does unqualified name lookup mean? §[basic.lookup.unqual]¶3:

> *Unqualified name lookup* from a program point performs an unqualified search in its immediate scope.

The definition of an unqualified search is given in §[basic.lookup.unqual]¶2:

> An *unqualified search* in a scope `S` from a program point `P` includes the results of searches from `P` in
>
> — `S`, and
>
> — for any scope `U` that contains `P` and is or is contained by `S`, each namespace contained by `S` that is nominated by a *using-directive* that is active in `U` at `P`.
>
> If no declarations are found, the results of the unqualified search are the results of an unqualified search in the parent scope of `S`, if any, from `P`.

So, since we don't have any using directives, we search for `foo` in its immediate scope and if we find any result, we stop searching. (If we don't, we keep searching in parent scopes, recursively.)

The immediate scope at some program point is the smallest scope that contains it (§[basic.scope.scope]¶1). What is the immediate scope at the program point where we call `foo`? §[basic.scope.class]¶1:

> Any declaration of a class or class template `C` introduces a *class scope* that includes the *member-specification* of the *class-specifier* for `C` (if any). For each non-friend redeclaration or specialization whose target scope is or is contained by the scope, the portion after the *declarator-id*, *class-head-name*, or *enum-head-name* is also included in the scope.

In the statement `int foobar::x = foo();` we redeclare the variable `x`. Its target scope is a class scope introduced by the declaration of the class `foobar` (§[dcl.meaning.general]¶3.4). The portion after `x` is also included in that scope. So when looking for `foo` we find `foobar::foo` there and don't search any further.