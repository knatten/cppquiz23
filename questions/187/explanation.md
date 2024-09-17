On the first line, `C c1;`, the object `c1` is default-initialized, so the default constructor is called, printing `1`.

On the second line, `C c2 = c1;`, the object `c2` is copy-initialized, so the copy constructor is called, printing `2`. (Note that no assignment is taking place, even though there's a `=` involved.)

Let's have a look at the standard:

§[dcl.init.general]¶14:

> The initialization that occurs in the `=` form of a *brace-or-equal-initializer* (...) is called *copy-initialization*.

The initialization of `C c2 = c1;` is the "equal" part of a braced-or-equal-initializer, so we have copy-initialization.

§[dcl.init.general]¶16:

> — (...)
>
> — Otherwise, if the destination type is a (possibly cv-qualified) class type (...), if the initialization is (...) copy-initialization where the cv-unqualified version of the source type is the same class as, or a derived class of, the class of the destination, constructors are considered. The applicable constructors are enumerated (§[over.match.ctor]), and the best one is chosen through overload resolution (§[over.match]). (...) If overload resolution is successful, the selected constructor is called to initialize the object, with the initializer expression or *expression-list* as its argument(s).

The destination type here is `C`, and the initialization is copy-initialization. The source type is the same class as the class of the destination, so constructors are considered. The only constructor taking a `C` as an argument is our copy constructor, which prints `2`.