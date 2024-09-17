According to §[dcl.ptr]¶1:

> The *cv-qualifiers* apply to the pointer and not to the object pointed to.

That is, constness is shallow with regard to raw pointers and references (and standard types that seek to emulate them, like `std::unique_ptr`) but not with regard to standard containers such as `std::vector`.

In the code above, the object `s` is non-const, and so its members all retain their default constness and all calls through them invoke the non-const version of `C::foo()`.

However, `r` refers to its object as a const instance of `S`. That constness changes the behavior of its member `v`, an `std::vector` which is "const-correct" in the sense that its `operator[]` returns `const C&` (see §[sequence.reqmts]¶118) and therefore invokes the const version of `C::foo()`.

The constness of `r`'s referent is also propagated to its members `u` and `p` (meaning one could not perform a mutating operation on `u`, e.g., calling `r.u.reset()`), but this has no effect on the instance of `C` that they both point *to*. That is, the pointers themselves become const, but the pointed-to objects remain non-const. Hence, they both still call the non-const version of `C::foo()`.

The constness of the member `S::p` is the same for both `s` and `r`. Because it is declared as a const pointer, it does not change constness to follow the constness of its instance of `S` but remains a const pointer to a non-const object.