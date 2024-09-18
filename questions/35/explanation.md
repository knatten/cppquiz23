To answer this we need to look at overload resolution of vector's constructors:

§[vector.cons]¶7 says:

> ```
> constexpr vector(size_type n, const T& value,
>                  const Allocator& = Allocator());
> ```
>
> *Effects*: Constructs a `vector` with `n` copies of `value`, using the specified allocator.

So `v1` contains one "`2`".

§[over.match.list] says (in summary) that when non-aggregate classes (such as `vector`) are list-initialized<sup>†</sup> and have an initializer list constructor (again, like `vector`), that constructor is chosen, and the argument list consists of the initializer list as a single argument.
(†: §[dcl.init.list]¶1: "List-initialization is initialization of an object or reference from a braced-init-list".)

So `v2` is initialized from the elements (aka initializer-clauses) in the braced-init-list, and contains the elements "`1`" and "`2`".