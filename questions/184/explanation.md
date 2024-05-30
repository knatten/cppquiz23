Why does overload resolution not pick the obviously better `void f(int)`, but instead `void f(double)` which requires a floating-integral conversion from `int` to `double`?

It turns out that `void f(int)` isn't even in scope, and is not considered for overload resolution at all. When the name `f` is introduced in `Derived`, it hides the name `f` that was introduced in `Base`.

§[basic.scope] in the C++ standard is dedicated to scope. §[basic.scope.hiding]¶1 and ¶3 has some hints about what's going on in our case:

¶1: "A name can be hidden by an explicit declaration of that same name in a nested declarative region or derived class (§13.2)"
¶3: "The declaration of a member in a derived class (Clause 13) hides the declaration of a member of a base class of the same name; see §13.2"

Both of these refer to §[class.member.lookup], so let's explore the details about how the name `f` is looked up in a class scope `C`:

§[class.member.lookup]¶4:
"If `C` contains a declaration of the name `f`, the declaration set contains every declaration of `f` declared in `C` that satisfies the requirements of the language construct in which the lookup occurs.(...) If the resulting declaration set is not empty, the subobject set contains C itself, and calculation is complete." 

So when looking for a declaration of `f` and finding `Derived::f`, the calculation is complete, and `Base` is not examined at all. If no `f` was found in `Derived`, we would continue with §[class.member.lookup]¶5:

"Otherwise (i.e., `C` does not contain a declaration of `f` or the resulting declaration set is empty), S(f,C) is initially empty. If C has base classes, calculate the lookup set for `f` in each direct base class subobject Bi, and merge each such lookup set S(f, Bi) in turn into S(f, C).

But since `Derived` does indeed contain a declaration of `f`, we never get around to looking at `Base`.
