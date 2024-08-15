§[dcl.spec.general]¶3 states:

> If a *type-name* is encountered while parsing a *decl-specifier-seq*, it is interpreted as part of the *decl-specifier-seq* if and only if there is no previous *defining-type-specifier* other than a *cv-qualifier* in the *decl-specifier-seq*.

§[dcl.spec.general]¶note-1 mentions our case specifically:

> Since `signed`, `unsigned`, `long`, and `short` by default imply `int`, a *type-name* appearing after one of those specifiers is treated as the name being (re)declared.

In `void foo(unsigned ll)`, since `unsigned` implies `int`, `ll` is being redeclared as a parameter name.