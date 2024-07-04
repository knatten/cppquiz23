What does the `std::variant` default constructor do? Which of the types does it pick, or is the variant empty? And if it picks one, how is the value initialized?

`std::variant`s default constructor constructs a variant holding the value-initialized value of the first alternative. So it picks `C` as the type and calls the `C::C()` default constructor initializing it with `i == 1`, which gets printed.

§[variant.ctor]¶3:

> In the descriptions that follow, let *i* be in the range `[0, sizeof...(Types))`, and T<sub>*i*</sub> be the *i*<sup>th</sup> type in `Types`.
>
> `constexpr variant() noexcept(see below);`
>
> (...)
>
> *Effects*: Constructs a `variant` holding a value-initialized value of type T<sub>0</sub>.

Now what does *value-initialized* mean?

§[dcl.init.general]¶9:

> To *value-initialize* an object of type `T` means:
>
> (...)
>
> — if `T` has either no default constructor (§[class.default.ctor]) or a default constructor that is user-provided or deleted, then the object is default-initialized;

`C` has a user-provided constructor, so it's default-initialized. Now what does *default-initialized* mean?

§[dcl.init.general]¶7.1:

> To *default-initialize* an object of type `T` means:

> — If `T` is a (possibly cv-qualified) class type (§[class]), constructors are considered. The applicable constructors are enumerated (§[over.match.ctor]), and the best one for the *initializer* `()` is chosen through overload resolution (§[over.match]). The constructor thus selected is called, with an empty argument list, to initialize the object.

There's only one default constructor, it gets called and initializes the `C` object with `i == 1`.