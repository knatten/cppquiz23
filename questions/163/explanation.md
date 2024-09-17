To get to the bottom of this, we need to take a detour via function templates.

According to §[dcl.spec.auto.general]¶7 (`auto` specifier) in the standard:

> The type of each declared variable is determined by placeholder type deduction (...).

Placeholder type deduction works as per §[dcl.type.auto.deduct]¶3:

> If the *placeholder-type-specifier* is of the form *type-constraint<sub>opt</sub>* `auto`, the deduced type `T′` replacing `T` is determined using the rules for template argument deduction. (...) Deduce a value for `U` [the template parameter for the invented function] using the rules of template argument deduction from a function call (...).

So the rules for `auto bar = a.getFoo();` are the same as if we did

```
template<typename T> void f(T t);
f(a.getFoo());
```

Let's have a look at §[temp.deduct.call]¶4:

> In general, the deduction process attempts to find template argument values that will make the deduced `A` identical to `A` [where `A` is the type of the argument of the call] (...).

Now what is the type of the argument of the call? `getFoo()` returns `int&`, but let's see what §[expr.type]¶1 has to say about the type of expressions:

> If an expression initially has the type “reference to `T`” (§[dcl.ref], §[dcl.init.ref]), the type is adjusted to `T` prior to any further analysis.

So the type of the expression `a.getFoo()` that is used for deduction is `int`, not `int&`. Now `int` is being used for deducing `T` in our imaginary void `f(T t)`, so `T` is `int`. Since `auto` uses the same rule, the type of `bar` is also `int`.

Since `bar` is not a reference, incrementing it does not increment `foo`, and the output of the program is `0`.