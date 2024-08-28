§[expr.typeid]¶1:
> "The result of a `typeid` expression is an lvalue of static type `const std::type_info`

and §[expr.unary.op]¶3:
> The operand of the unary `&` operator shall be an lvalue of some type `T`. The result is a prvalue.
>
> (...) the result has type “pointer to T” and points to the designated object

So we're comparing two pointers to `const std::type_info`.

There is no guarantee that the same `std::type_info` instance will be referred to by all evaluations of the `typeid` expression on the same type, although `std::type_info::hash_code` of those `type_info` objects would be identical, as would be their `std::type_index`.

(For more info on `hash_code(), see` §[type.info]¶6 : "`hash_code()` (...)shall return the same value for any two `type_info` objects which compare equal")

(For more info on `type_index` equality, see §[type.index.members] and §[type.info])