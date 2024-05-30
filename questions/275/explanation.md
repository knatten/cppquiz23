The sizes of the standard integer types are not fixed by the standard. It's perfectly legal to for instance have an implementation where both `long` and `int` are 32 bits.

What _do_ we know about the sizes of `long` and `int` though? 
§[basic.fundamental]¶2 in the standard:

> There are five standard signed integer types : “`signed char`”, “`short int`”, “`int`”, “`long int`”, and “`long long int`”. In this list, each type provides at least as much storage as those preceding it in the list. (...) Plain ints have the natural size suggested by the architecture of the execution environment <sup>47</sup> ; the other signed integer types are provided to meet special needs.

So we know that `long` is at least as big as `int`. But how big is an int? Here's  footnote 47:
> `int` must also be large enough to contain any value in the range `[INT_MIN, INT_MAX]`, as defined in the header `<climits>`.

The `<climits>` header is discussed in §[climits.syn]:
> (...)
> `#define INT_MIN` _see below_
> `#define INT_MAX` _see below_
> (...)
> The header `<climits>` defines all macros the same as the C standard library header `<limits.h>`

So it turns out we actually have to go to the C standard to find the answer! And the C standard defines `INT_MIN` and `INT_MAX` to at least have magnitudes −(2<sup>15</sup>−1) and  2<sup>15</sup>−1, i.e. `int` has to be at least 16 bits. For `long`, the minimum magnitudes are −(2<sup>31</sup>−1) and  2<sup>31</sup>−1, i.e. 32 bits. But it's perfectly legal for them both to be 32 bits.

Luckily, in C++20, the minimum widths of integer types will be defined in the actual C++ standard.