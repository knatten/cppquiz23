`nullptr` is a prvalue of type `std::nullptr_t`, which is not actually a pointer type. Instead, `nullptr` is a "null pointer constant" which can be *converted* to a pointer.

§[lex.nullptr]¶1 in the standard:

> The pointer literal is the keyword nullptr. It has type std::nullptr_t.
>
> [Note 1: `std::nullptr_t` is a distinct type that is neither a pointer type nor a pointer-to-member type; rather, a prvalue of this type is a null pointer constant and can be converted to a null pointer value or null member pointer value. See §[conv.ptr] and §[conv.mem]. —end note]