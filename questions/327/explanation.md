`S::operator&` has been overloaded to return the address of the global `S global`, rather than the address of whichever `S` object the caller calls it on. This would cause infinite recursion, since the implementation does `&global` which would call the same `S::operator&` again.

The question then is whether `std::addressof` calls `S::operator&` at all.

§[specialized.addressof]¶1 in the standard has the answer:

> `template <class T> constexpr T* addressof(T& r) noexcept;`
>
> *Returns:* The actual address of the object or function referenced by `r`, even in the presence of an overloaded `operator&`.

So `addressof` ignores the overloaded `operator&`, and this is indeed its purpose. It computes the *actual* address of `s`, and we can then print its member `i_` which holds the value `2`.