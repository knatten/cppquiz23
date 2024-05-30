Since C++11, `std::vector` has a one parameter constructor ( + allocator). §[vector.cons]¶3 in the standard):

`explicit vector(size_type n, const Allocator& = Allocator())`

which constructs a vector with `n` value-initialized elements. Each value-initialization calls the default `Foo` constructor, resulting in the output `aaaaa` .

The "trick" is, that before C++11, `std::vector` had a 2 parameter constructor ( + allocator ), which constructed the container with `n` copies of the second parameter, which is defaulted to `T()`.

So this code before C++11 would output `abbbbb`, because the call would be equivalent to `std::vector<Foo> bar(5,Foo())`.