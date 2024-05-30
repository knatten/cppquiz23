In short, when the parameter is of a reference type, we use the referred-to type for type deduction. So for `foo`, we use `T`, and for `bar`, we use `const T`. Also, in the fourth call, we're allowed to deduce `int` to `const int`.

Only in the first case is `T` deduced as `const`, and `1` printed. In the other cases, `0` is printed.

### Details:

Let `P` be the parameter type in the function template.

For `foo`, `P` is `T&`, but we ignore the reference part. §[temp.deduct.call]¶3:
> If `P` is a reference type, the type referred to by `P` is used for type deduction.

So for `foo`, we simply use `T` for type deduction.

For `bar`,  `P` is `const T&`, but again we ignore the reference part.

So for `bar`, we use `const T` for type deduction.


Now we look at each call and try to deduce the type of `T`:

```
foo(i);
```

The type of the argument is `const int`. The type of the parameter is `T&`, but remember that we're ignoring the reference and only try to match against `T`. If we choose `T` as `const int`, we have `const int` deduced to `const int`.

Since `T` is `const int`, we print `1`. 


```
foo(j);
```

The type of the argument is `int`. The type of the parameter is `T&`, but we only try to match against `T`. If we choose `T` as `int`, we have `int` deduced to `int`.

Since `T` is `int`, we print `0`.
   
```
bar(i);
```

The type of the argument is `const int`. The type of the parameter is `const T&`, but we only try to match against `const T`. If we choose `T` as `int`, we have `const int` deduced to `const int`.

Since `T` is `int`, we print `0`.

```
bar(j);
```

The type of the argument is `int`. The type of the parameter is `const T&`, but we only try to match against `const T`. There seems to be no way we can choose `T` so `int` deduces to `const T`! After all, if we choose `T = int`, we try to deduce `int` to `const int`, which seems to not be a match. And if we choose `T = const int` we try to deduce `int` to `const const int` which doesn't make sense. The solution comes from  §[temp.deduct.call]¶4, which allows us  to deduce a non-const argument to a const parameter:

> If the original `P` is a reference type, the deduced `A` (i.e., the type referred to by the reference) can be more cv-qualified than the transformed `A`.

If we choose `T` as `int`, we have `int` deduced to `const int`, which is fine since `const int` is more cv-qualified than `int`.

Since `T` is `int`, we print `0`.


### Appendix:

If you read the rest of §[temp.deduct.call]¶3, you might have noticed:

> If `P` is a cv-qualified type, the top-level cv-qualifiers of `P`'s type are ignored for type deduction.

So when `P` is `const T&`, should we ignore `const` and only use `T` for type deduction? We should not, since `const` here is not a _top-level_ cv-qualifier. What is a top-level cv-qualifier? If `P` was `const T * const`, the top-level qualifier would be the rightmost `const`. You can have a const pointer pointing to something const or non-const. With references on the other hand, you can have a _reference to const_, but not a _const reference to something_. References do not _have_ a top-level qualifier.