`std::min()` and `std::max()` return references to their smallest/largest arguments, respectively. But what if they're equal?

The C++ standard says both for `std::min()` in §[alg.min.max]¶2 and for `std::max()` in §[alg.min.max]¶10:

> Returns the first argument when the arguments are equivalent.

So both the evaluation of `std::max(x,y)` and `std::min(x,y)` return `x`, and both references `max` and `min` are bound to `x`.

We then set `x` to `11`, and print `max` and `min`, which are now both `11`.

Some say it would be better if `min()` returned its first element, but `max()` returned its *last* element. Sean Parent explains his rationale for this in his BoostCon 2016 Keynote [Better Code]( https://www.youtube.com/watch?v=giNtMitSdfQ&t=1448s).