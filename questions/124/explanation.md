§[temp.param]¶14 in the C++ standard says: "A template-parameter of a template template-parameter is permitted to have a default template-argument.
When such default arguments are specified, they apply to the template template-parameter in the scope of
the template template-parameter."

In this code snippet, the template template-parameter is `C`, and the scope of `C` is the function template `g()`. Therefore, the default template argument for `C` (which is `T = B`) is applied. This means that when `g<X>()` is called, it is equivalent to calling `g<X<B>>()`, which in turn calls `X<B>::f()`. As `X<B>::f()` is specialized to print 2, the output of the program is 2.