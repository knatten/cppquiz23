`std::variant` can hold a value of any one of its alternative types, or no value. To refer to the alternative types, it uses an index `i`.

§[variant.ctor]¶1 in the standard:
> let `i` be in the range `[0, sizeof...(Types))`, and `T`<sub>i</sub> be the i<sup>th</sup> type in `Types`.

In our case, `T`<sub>0</sub> means `int`, `T`<sub>1</sub> means `double`, and `T`<sub>2</sub> means `char`.

Now what happens if you define a `variant` without initializing it with a certain type? The default constructor will pick the type `T`<sub>0</sub>, in our case `int`, and value-initialize it.

§[variant.ctor]¶3:

> ```
> constexpr variant() noexcept(see below);
> ```
>
> Constructs a `variant` holding a value-initialized value of type `T`<sub>0</sub>

Finally, we call `index()` and print the result. `index()` returns the index of the type of the contained value. The contained value is an `int`, aka `T`<sub>0</sub>, so `0` is returned.

§[variant.status]¶3:

> ```
> constexpr size_t index() const noexcept;
> ```
>
> _Effects+: If [it doesn't contain a value], returns `variant_npos`. Otherwise, returns the zero- based index of the alternative of the contained value.