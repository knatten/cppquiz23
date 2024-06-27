First, a `Q` instance is default-constructed in `takeQfunc()`, printing `D`.
Then `q.func()` is called, which prints `0`.
Next, we call `qfunc(q)`. Although the lambda's parameter list specifies that it takes an rvalue reference `Q&&`, the `q` is actually first passed to `qfunc`, which takes a plain `Q` by value. A copy is made, printing `C`. Then, the `std::function::operator()` `std::forward`s its argument to the lambda, and the lambda's rvalue reference can bind to the newly copied `q`. Since the reference binds to this copy rather than the original, `q.change()` doesn't change the original `q`.
Then, `q.func()` is called again, which prints `0`.

### Details about the call to `qfunc`:

`std::function` is declared like this §[func.wrap.func.general]:

```
template<class R, class... ArgTypes>
class function<R(ArgTypes...)> {
    (...)
    R operator()(ArgTypes...) const;
    (...)
}
```

`takeFunc` explicitly specializes what kind of `std::function` it accepts (rather than e.g. being a function template that deduces it from the lambda we pass to it). It explicitly sets the return type `R` to `void`, and the template parameter pack `ArgTypes...` to `Q`. That means that the signature of `operator()` is `void operator()(Q) const`; taking `Q` by value.
 
§[func.wrap.func.inv]¶1 continues:
 
> `R operator()(ArgTypes... args) const;`
>
> *Returns*: `INVOKE<R>(f, std​::​forward<ArgTypes>(args)...)` (§[func.require]), where `f` is the target object (§[func.def]) of `*this`.

If we substitute the types in `INVOKE<R>(f, std​::​forward<ArgTypes>(args)...)`, we get `INVOKE<void>(f, std​::​forward<Q>(q))`, which just means `f(std::forward<Q>(q))`.

So when we call `qfunc(q)`, it passes `q` by value to `qfunc`. The `std::function::operator()` then wraps that copy in `std::forward<Q>`, turning it into an rvalue reference (§[forward]¶3), before passing it to the lambda. The `Q&&` parameter to our lambda can bind directly to this forwarded `q`, no move is necessary.

Then, the lambda calls `q.change()` on this copied `q`, which modifies the `v` member. But this copy of `q` is never used again.