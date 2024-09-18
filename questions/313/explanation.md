### Explanation

The function template `g` instantiates to `void g<float,int>(float&& v1, int&& v2) { f(v1), f(v2); }`, which sequences the call to `f(v1)` before `f(v2)`. However, `f(v1)` (the `float`) calls the `int&&` overload, and `f(v2)` (the `int`) calls the `float&&` overload!

`f(v1)` can't call the `float&&` overload, because that would bind an rvalue reference to an lvalue. It can, however, call the `int&&` overload by converting the float to a prvalue `int`. So the `float` call calls the `int` overload and vice versa.

### Detailed explanation

First, the template parameter pack is deduced as `float, int`, and the function parameter pack `(T &&... v)` is expanded to `(float&& v1, int&& v2)`, since `1.0f` is a floating-point literal and `2` is an integer literal.

Inside `g`, the named rvalue references `v1` and `v2` are treated as lvalues. §[basic.lval]¶note-3:

> In general, the effect of this rule is that named rvalue references are treated as lvalues and unnamed rvalue references to objects are treated as xvalues (...).

The body of `g` consists of the fold-expression `(f(v), ...)` which is a unary right fold with `f(v)` as a cast-expression and `,` as a fold-operator. §[expr.prim.fold]¶2:

> An expression of the form (... *op* e) where *op* is a *fold-operator* is called a *unary left fold*. An expression of the form (e *op* ...) where *op* is a *fold-operator* is called a *unary right fold*.

The instantiation of the unary right fold produces `f(v1), f(v2)`. §[temp.variadic]¶10.2:

> The instantiation of a *fold-expression* (§[expr.prim.fold]) produces:
>
> — (...)
>
> — E<sub>1</sub> *op* (... *op* (E<sub>N-1</sub> *op* E<sub>N</sub>)) for a unary right fold,

Now we need to do overload resolution for `f`, based on the arguments in the two calls. First of all, `int&&` is reference-related to `int&&`, and `float&&` is reference-related to `float&&`.

§[dcl.init.ref]¶4:

> Given types “*cv1* `T1`” and “*cv2* `T2`”, “*cv1* `T1`” is reference-related to “*cv2* `T2`” if `T1` is similar (§[conv.qual]) to `T2`, or `T1` is a base class of `T2`.

§[conv.qual]¶2:

> Two types `T1` and `T2` are similar if they have qualification-decompositions with the same *n* such that corresponding *P<sub>i</sub>* components are either the same or one is “array of *N<sub>i</sub>*” and the other is “array of unknown bound of”, and the types denoted by `U` are the same.

§[conv.qual]¶1:

> A *qualification-decomposition* of a type `T` is a sequence of *cv<sub>i</sub>* and *P<sub>i</sub>* such that `T` is
>
> “*cv*<sub>0</sub> *P*<sub>0</sub> *cv*<sub>1</sub> *P*<sub>1</sub> ... *cv*<sub>*n*-1</sub> *P*<sub>*n*-1</sub> *cv<sub>n</sub>* `U`” for *n* ≥ 0,
>
> where each *cv<sub>i</sub>* is a set of cv-qualifiers (§[basic.type.qualifier]), and each *P<sub>i</sub>* is “pointer to” (§[dcl.ptr]), “pointer to member of class *C<sub>i</sub>* of type” (§[dcl.mptr]), “array of *N<sub>i</sub>*”, or “array of unknown bound of” (§[dcl.array]).

Since `T1` is reference-related to `T2`, we can't initialize the rvalue reference with an lvalue. §[dcl.init.ref]¶5.4.4:

> If `T1` is reference-related to `T2`:
>
> — (...)
>
> — if the reference is an rvalue reference, the initializer expression shall not be an lvalue.

This means we can't directly bind the reference to the initializer expression here. We can however implicitly convert the `float` to a prvalue `int` using a standard conversion sequence (floating-integral conversion) and bind the `int &&` to it.

To get the "intuitively expected" order of the function calls we can simply use `std::forward` and rewrite fold-expression like this: `(f(std::forward<decltype(v)>(v)), ...);`.