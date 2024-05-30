According to §[dcl.type.simple]¶4 in the C++ standard:
"The type denoted by decltype(e) is deﬁned as follows:
- if e is an unparenthesized id-expression naming a structured binding (§[dcl.struct.bind]), decltype(e) is the referenced type as given in the specification of the structured binding declaration;
— if e is an unparenthesized id-expression or an unparenthesized class member access (§[expr.ref]), decltype(e) is the type of the entity named by e. If there is no such entity, or if e names a set of overloaded functions, the program is ill-formed;
— otherwise, if e is an xvalue, decltype(e) is T&&, where T is the type of e;
— otherwise, if e is an lvalue, decltype(e) is T&, where T is the type of e;
— otherwise, decltype(e) is the type of e."

Because `a` is encapsulated in parentheses, it doesn't qualify for the first case, it is treated as an lvalue, therefore `b`'s type is `int&`, not `int`.
