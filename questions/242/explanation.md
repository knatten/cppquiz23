`42` is an rvalue, `i` is an lvalue. How does this impact the template parameter `T` and the type of `t`?

The first thing to do when deducing a template parameter `P` is to ignore references:

§[temp.deduct.call]¶3:

> If `P` is a reference type, the type referred to by `P` is used for type deduction.

In our case, `P` is `T&&`, which is indeed a reference type. So `T` is used for type deduction. `42` is an `int`, `T` is deduced to `int`, and `1` is printed.

There is however this additional rule:

§[temp.deduct.call]¶3:

> A *forwarding reference* is an rvalue reference to a cv-unqualified template parameter (...). If `P` is a forwarding reference and the argument is an lvalue, the type “lvalue reference to `A`” is used in place of `A` for type deduction.

(cv-unqualified just means no `const` or `volatile`)

`T&&` is indeed an rvalue reference to a cv-unqualified template parameter, so it is a forwarding reference.

In the case of `f(42)` which we saw above, the argument was *not* an lvalue, so this rule did not apply.

In the case of `f(i)` however, `i` *is* an lvalue, and the rule applies. `int&` is used in place of `int` for type deduction. `T` is deduced to `int&`, and `2` is printed.

Now, which overload of `g` is called in the two cases?

In both cases, `t` itself is an lvalue, so without the call to `std::forward`, `g(int&)` would be called. With the use of `std::forward` however, we can change that.

§[forward]¶3 explains what `std::forward` does:

> ```
> template<class T> constexpr T&& forward(remove_reference_t<T>& t) noexcept;
> template<class T> constexpr T&& forward(remove_reference_t<T>&& t) noexcept;
> ```
>
> *Mandates*: For the second overload, `is_lvalue_reference_v<T>` is `false`.
>
> *Returns*: `static_cast<T&&>(t)`.

In the case of `f(42)`, `T` is `int`, and `std::forward` returns `static_cast<int&&>(t)`. The result is an rvalue, `g(int&&)` is selected, and `R` is printed.

In the case of `f(i)`, `T` is `int&`, and `std::forward` would return `static_cast<int&&&>(t)`. However, `int&&& t` collapses to `int&` (see [1] below), and it returns `static_cast<int&>(t)` instead. The result is an lvalue, `g(int&)` is selected, and `L` is printed.

### Notes

[1] Reference collapsing

Reference collapsing explains how `int&&&` above collapsed to `int&`. The mechanism is defined in the section about typedef-names:

§[dcl.ref]¶6:

> If a *typedef-name* (...) denotes a type `TR` that is a reference to a type `T`, an attempt to create the type “lvalue reference to *cv* `TR`” creates the type “lvalue reference to `T`”, while an attempt to create the type “rvalue reference to *cv* `TR`” creates the type `TR`.
>
> [*Note 3*: This rule is known as reference collapsing. — *end note*]

But what does template parameters have to do with typedef-names? It turns out that template-parameters *are* typedef-names: §[temp.param]¶3:

> A *type-parameter* whose *identifier* does not follow an ellipsis defines its *identifier* to be a *typedef-name* (...) in the scope of the template declaration.

So reference collapsing applies to template parameters as well.

In the case of `f(i)`, `T` is `int&`, and we're doing `T&&`. So according to the quote above, our `TR` is `int&`, and we're attempting to create the type “rvalue reference to `int&`”, which creates the type `int&`.