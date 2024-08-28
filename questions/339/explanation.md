You can only `get` the value from a `future` once. It is undefined behaviour to call `get` multiple times, but implementations are encouraged to throw an exception, and most (such as GCC, Clang and MSVC) also [do so at the same of writing](https://www.godbolt.org/z/aWeWsvrM5).

More details:

First, we call `get` for the first time. §[futures.unique.future]¶16:

> ```
> R future::get();
> R& future<R&>::get();
> void future<void>::get();
> ```
>
> *Effects*:
>
> — `wait()`s until the shared state is ready, then retrieves the value stored in the shared state;
>
> — releases any shared state (§[futures.state]).

So the first call to `get` gets the value, and releases the shared state. What does it mean to release the shared state? §[futures.state]¶5:

> When an asynchronous return object [the `future` in this case] (...) is said to release its shared state, it means:
>
> — (...)
>
> — the return object (...) gives up its reference to its shared state; (...)

Then we try to call `get` again, but §[futures.unique.future]¶3 says:

> The effect of calling any member function other than the destructor, the move-assignment operator, `share`, or `valid` on a `future` object for which `valid() == false` is undefined.
>
> (...)
>
> *Recommended practice*: Implementations should detect this case and throw an object of type `future_error` with an error condition of `future_errc​::​no_state`.

So if `valid() == false`, calling `get` a second time is UB (but an exception is usually thrown). What does `valid()` do? §[futures.unique.future]¶20:

> ```
> bool valid() const noexcept;
> ```
>
> *Returns*: `true` only if `*this` refers to a shared state.

The first time we called `get`, we gave up our reference to the shared state, and from then on `*this` no longer refers to a shared state, `valid()`  now returns `false`, and calling `get` again is UB.