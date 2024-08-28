The derived class constructor `B()` first calls the base class constructor `A()`, and then executes the compound-statement (the part inside `{}`) of its own body.

The derived class destructor `~B()` first executes its own body, and then calls the base class destructor `~A()`.

Let's have a look at the standard:

Initialization order is defined in  §[class.base.init]¶13:

> In a non-delegating constructor, initialization proceeds in the following order:
>
> — (...)
>
> — Then, direct base classes are initialized in declaration order as they appear in the *base-specifier-list* (regardless of the order of the *mem-initializer*s).
>
> — (...)
>
> — Finally, the *compound-statement* of the constructor body is executed.

Destruction order is defined in §[class.dtor]¶13:

> After executing the body of the destructor and destroying any objects with automatic storage duration allocated within the body, a destructor for class `X` calls (...) the destructors for `X`'s non-virtual direct base classes (...).