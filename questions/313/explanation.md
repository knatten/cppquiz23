### Explanation

The function template `g` instantiates to `void g<float,int>(float&& v1, int&& v2) { f(v1), f(v2); }`, which sequences the call to `f(v1)` before `f(v2)`. However, `f(v1)` (the `float`) calls the `int&&` overload, and `f(v2)` (the `int`) calls the `float&&` overload!

`f(v1)` can't call the `float&&` overload, because that would bind an rvalue reference to an lvalue. It can, however, call the `int&&` overload by converting the float to a prvalue `int`. So the `float` call calls the `int` overload and vice versa.

### Detailed explanation

First, the template parameter pack is deduced as `float, int`, and the function parameter pack `(T &&... v)` is expanded to `(float&& v1, int&& v2)`, since `1.0f` is a floating-point literal and `2` is an integer literal.

Inside `g`, the named rvalue references `v1` and `v2` are treated as lvalues. §[expr]¶7:
> In general, the effect of this rule is that named rvalue references are treated as lvalues and unnamed rvalue references to objects are treated as xvalues; [...]

The body of `g` consists of the fold-expression `(f(v), ...)` which is a unary right fold with `f(v)` as a cast-expression and `,` as a fold-operator. §[expr.prim.fold]¶2: 
> An expression of the form (... op e) where op is a fold-operator is called a unary left fold. An expression of the form (e op ...) where op is a fold-operator is called a unary right fold. [...]

The instantiation of the unary right fold produces `f(v1), f(v2)`. §[temp.variadic]¶9.2:
> E_1 op (... op (E_(n-1) op E_n)) for a unary right fold

Now we need to do overload resolution for `f`, based on the arguments in the two calls. First of all, `int&&` is reference-related to `int&&`, and `float&&` is reference-related to `float&&`. §[dcl.init.ref]¶4:
> Given types "cv1 `T1`" and "cv2 `T2`", "cv1 `T1`" is reference-related to "cv2 `T2`" if `T1` is the same type as `T2`, or `T1` is a base class of `T2`.

Since `T1` is reference-related to `T2`, we can't initialize the rvalue reference with an lvalue. §[dcl.init.ref]¶5.2.2.4:
> If `T1` is reference-related to `T2`:
>
> — if the reference is an rvalue reference, the initializer expression shall not be an lvalue.

This means we can't directly bind the reference to the initializer expression here. We can however implicitly convert the `float` to a prvalue `int` using a standard conversion sequence (floating-integral conversion) and bind the `int &&` to it.

To get the "intuitively expected" order of the function calls we can simply use `std::forward` and rewrite fold-expression like this: `(f(std::forward<decltype(v)>(v)), ...);`