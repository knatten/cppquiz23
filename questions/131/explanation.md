These are two examples of initialization. The first form, `C c1(7)`, is called direct-initialization, the second, `C c2 = 7`, is called copy-initialization. In most cases they are equivalent, but in this example they are not, since the `int` constructor is `explicit`.

The key is in §[over.match.copy]¶1 :
"[...] as part of a copy-initialization of an object of class type, a user-defined conversion can be invoked to convert an initializer expression to the type of the object being initialized. [...] the candidate functions are selected as follows:
- [...]
- When the type of the initializer expression is a class type "cv `S`", the *non-explicit* conversion functions of `S` and its base classes are considered. [...]
(emphasis added)

And how is direct-initialization defined?

§[dcl.init]¶16: "The initialization that occurs in the forms
`T x(a);`
`T x{a};`
(...) is called direct-initialization."

So the `int` constructor is not even considered for initialization in the second case. Instead, a standard conversion sequence is used to convert the integer literal to a `double`, and the `double` constructor (the only candidate) is used.