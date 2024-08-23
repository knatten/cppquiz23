Since C++11, `std::vector` has a one parameter constructor (+ optional allocator). §[vector.cons]¶4 in the standard:

> `constexpr explicit vector(size_type n, const Allocator& = Allocator());`
>
> *Effects*: Constructs a `vector` with `n` default-inserted elements using the specified allocator.

Default-insertion uses value-initialization, which calls the `Foo` default constructor, resulting in the output `aaaaa`.

The "trick" is, that before C++11, `std::vector` had a two parameter constructor ( + optional allocator ), which constructed the container with `n` copies of the second parameter, which is defaulted to `T()`.

So this code before C++11 would output `abbbbb`, because the call would be equivalent to `std::vector<Foo> bar(5,Foo())`.