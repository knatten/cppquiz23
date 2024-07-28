`'0'` is a character literal, with type `char`. (The value of `'0'` is actually implementation defined, but will typically be `48`.) This value is then promoted to an `int`, and stored in `a`.

We then take a reference `b` to `a`. But `b` is a `char` reference, not an `int` reference, so it can not bind directly to the `int`.

§[dcl.init.ref]¶5 has a lot of rules, but since we're not dealing with rvalues or classes, the main part that decides whether we can bind directly is §[dcl.init.ref]¶5.1:

> — If the reference is an lvalue reference and the initializer expression (...) is an lvalue (...), and “*cv1* `T1`” is reference-compatible with “*cv2* `T2`” (...)

Are our types reference-compatible? §[dcl.init.ref]¶4:

> “*cv1* `T1`” is *reference-compatible* with “*cv2* `T2`” if a prvalue of type “pointer to *cv2* `T2`” can be converted to the type “pointer to *cv1* `T1`” via a standard conversion sequence (§[conv]).

A pointer to `int` can not be converted to a pointer to `char const` via any standard conversion (§[conv.ptr] in particular), so the types are not reference-compatible. Since they're not, §[dcl.init.ref]¶5.4.2 applies:

> — Otherwise, the initializer expression is implicitly converted to a prvalue of type “`T1`”. The temporary materialization conversion is applied, considering the type of the prvalue to be “*cv1* `T1`”, and the reference is bound to the result.

So the initializer expression `a` is converted to a temporary `char const`, which `b` refers to.

We then print `b`, which refers to our temporary `char` `'0'`.

We then increment the original `a`, which importantly does not modify the temporary that `b` refers to.

We finally print `b` again, which still prints `0`.