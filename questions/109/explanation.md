The compiler tries to deduce `T` for every parameter and checks if the deduced types match. Because a lambda is of completely different type, it cannot be matched against `std::function<void(T)>` and the deduction process fails. §[temp.deduct.type]¶2:

> Type deduction is done independently for each `P/A` pair, and the deduced template argument values are then combined. If type deduction cannot be done for any `P/A` pair, (...) template argument deduction fails. 

This problem can be fixed by turning the first parameter into a so-called nondeduced context.

§[temp.deduct.type]¶5 in the standard:

> The non-deduced contexts are:
>
> — The *nested-name-specifier* of a type that was specified using a *qualified-id*.
>
> — (...)

And also §[temp.deduct.type]¶6:
 
> When a type name is specified in a way that includes a non-deduced context, all of the types that comprise that type name are also non-deduced. However, a compound type can include both deduced and non-deduced types.
>
> [*Example 2*: If a type is specified as `A<T>​::​B<T2>`, both `T` and `T2` are non-deduced. Likewise, if a type is specified as `A<I+J>​::​X<T>`, `I`, `J`, and `T` are non-deduced. If a type is specified as `void f(typename A<T>​::​B, A<T>)`, the `T` in `A<T>​::​B` is non-deduced but the `T` in `A<T>` is deduced. — *end example*]

In particular, a helper struct template that typedefs the template parameter can be used:

```
template <typename T>
struct type_identity
{
    typedef T type;
};
```

This helper struct can then turn `std::function<void(T)>` into a nondeduced context:

```
template <typename T>
void call_with(typename type_identity<std::function<void(T)>>::type f, T val)
{
    f(val);
}
```

`std::type_identity` is available in the standard library since C++20.

The problem can also be solved in a less general way (at each call site) by explicitly specifying the template argument:

```
call_with<int>(print, 42);
```