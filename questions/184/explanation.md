Why does overload resolution not pick the obviously better `void f(int)`, but instead `void f(double)` which requires a floating-integral conversion from `int` to `double`?

It turns out that `void f(int)` isn't even found by name lookup, and is not considered for overload resolution at all. When the name `f` is introduced in `Derived`, it hides the name `f` that was introduced in `Base`.

Let's explore the details about how the name `f` is looked up in a class scope *C*:

§[class.member.lookup]¶3:

> The declaration set is the result of a single search in the scope of *C* for *N* from immediately after the *class-specifier* of *C* if *P* is in a complete-class context of *C* (...). If the resulting declaration set is not empty, the subobject set contains *C* itself, and calculation is complete.

So when looking for a declaration of `f` and finding `Derived::f`, the calculation is complete, and `Base` is not examined at all. If no `f` was found in `Derived`, we would continue with §[class.member.lookup]¶4:

> Otherwise (...), *S*(*N*,*C*) is initially empty. Calculate the lookup set for *N* in each direct non-dependent (§[temp.dep.type]) base class subobject *B<sub>i</sub>*, and merge each such lookup set *S*(*N*,*B<sub>i</sub>*) in turn into *S*(*N*,*C*).

But since `Derived` does indeed contain a declaration of `f`, we never get around to looking at `Base`.