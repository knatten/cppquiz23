`b` is a `Base` reference referring to an object of type `Derived`. But since `Base` has no virtual functions, there is no runtime type information for it, and `typeid(b)` returns the type `Base` rather than `Derived`. The comparison returns `false`, and `0` is printed.

### Details:

First of all, we can ignore that `b` is a reference. `typeid` will return type information about the type which is referred to. §[expr.typeid]¶5:

> If the type of the *type-id* is a reference to a possibly cv-qualified type, the result of the `typeid` expression refers to a `std​::​type_info` object representing the cv-unqualified referenced type.

But what does `typeid(b)` result in? Its static type `Base`, or its dynamic type `Derived`? §[expr.typeid]¶4:

> When `typeid` is applied to an expression other than a glvalue of a polymorphic class type, the result refers to a `std::type_info` object representing the static type of the expression.

Is `Base` a polymorphic class type? No. §[class.virtual]¶1:

> A class with a virtual member function is called a *polymorphic class*.

Since there are no virtual functions in `Base`, it does not count as a polymorphic class. So then `typeid` returns the static type `Base` instead of the dynamic type `Dynamic`.

The reason for this inconvenience is the "don't pay for what you don't use" principle. A C++ class instance carries no type information around with it if it doesn't need to. If the class has virtual functions, some type information (typically in the form of a vtable pointer) is needed in order to polymorphically select the correct derived function.