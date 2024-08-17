The `T&&` in the templated function doesn't necessarily result in an rvalue reference, it depends on the type that is used to instantiate the template. If instantiated with an lvalue, it collapses to an lvalue reference, if instantiated with an rvalue, it collapses to an rvalue reference. See note [1].

Scott Meyers has written a very good article about this, where he introduces the concept of "universal references" (the official term is "forwarding reference") <https://isocpp.org/blog/2012/11/universal-references-in-c11-scott-meyers>.

In this example, all three functions are called once with an lvalue and once with an rvalue. In all cases, calling with an lvalue (`i`) collapses `T&& x` to `int& x` (an lvalue reference), and calling with an rvalue (`20`) collapses `T&& x` to `int&& x` (an rvalue reference). Inside the functions, `x` itself is always an lvalue, no matter if its type is an rvalue reference or an lvalue reference.

- For the first example, `y(int&)` is called for both cases. Output: `11`.
- For the second example, `std::move(x)` obtains an rvalue reference, and `y(int&&)`is called for both cases. Output: `22`.
- For the third example, `std::forward<T>(x)` obtains an lvalue reference when `x` is an lvalue reference, and an rvalue reference when `x` is an rvalue reference, resulting in first calling `y(int&)` and then calling `y(int&&)`. Output: `12`.

Note [1]: §[dcl.ref]¶6 in the standard:

> If a *typedef-name* (§[dcl.typedef], §[temp.param]) or a *decltype-specifier* (§[dcl.type.decltype]) denotes a type `TR` that is a reference to a type `T`, an attempt to create the type “lvalue reference to *cv* `TR`” creates the type “lvalue reference to `T`”, while an attempt to create the type “rvalue reference to *cv* `TR`” creates the type `TR`.

The example at the end of that paragraph is worth a look. 

Note from the contributor: This demonstrates Scott Meyers's advice to use `std::forward` for forwarding references, and `std::move` for rvalue references.