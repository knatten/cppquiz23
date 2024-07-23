We're declaring a pointer to an `A<B>`. In the definition of `A`, we do `static_assert(T::value)`, where `T::value` becomes `B::value`, which is `false`. Do we then get a compilation error from the `static_assert`? §[temp.inst]¶2:

> Unless a class template specialization is a declared specialization, the class template specialization is implicitly instantiated when the specialization is referenced in a context that requires a completely-defined object type or when the completeness of the class type affects the semantics of the program.

And what does declared specialization mean? §[temp.inst]¶1:

> A template specialization `E` is a *declared specialization* if there is a reachable explicit instantiation definition (§[temp.explicit]) or explicit specialization declaration (§[temp.expl.spec]) for `E`, or if there is a reachable explicit instantiation declaration for `E` and (...)

The class template specialization `A<B>` has not been explicitly instantiated nor explicitly specialized, so the question is then whether it's implicitly instantiated. We're only declaring a pointer to it, which doesn't require a completely-defined object type, so it's not instantiated. The program compiles just fine, and `1` is printed.

If we had for instance done `A<B> a` instead, we would have instantiated `A<B>`, and gotten a compilation error.