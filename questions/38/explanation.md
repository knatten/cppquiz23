According to §[dcl.type.decltype]¶1 in the standard:

> For an expression `E`, the type denoted by `decltype(E)` is defined as follows:
>
> — if `E` is an unparenthesized *id-expression* naming a structured binding (§[dcl.struct.bind]), `decltype(E)` is the referenced type as given in the specification of the structured binding declaration;
>
> — otherwise, if `E` is an unparenthesized *id-expression* naming a non-type *template-parameter* (§[temp.param]), `decltype(E)` is the type of the *template-parameter* after performing any necessary type deduction (§[dcl.spec.auto], §[dcl.type.class.deduct]);
>
> — otherwise, if `E` is an unparenthesized *id-expression* or an unparenthesized class member access (§[expr.ref]), `decltype(E)` is the type of the entity named by `E`. If there is no such entity, the program is ill-formed;
>
> — otherwise, if `E` is an xvalue, `decltype(E)` is `T&&`, where `T` is the type of `E`;
>
> — otherwise, if `E` is an lvalue, `decltype(E)` is `T&`, where `T` is the type of `E`;
>
> — otherwise, `decltype(E)` is the type of `E`.

Because `a` is encapsulated in parentheses, it doesn't qualify for the first three cases, it is treated as an lvalue, therefore `b`'s type is `int&`, not `int`.