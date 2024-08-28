Can you use `override` as a type name, or is it a reserved keyword?

§[lex.key] in the standard lists reserved keywords. `override` is not one of those. However, §[lex.name]¶2 says about `override` and `final`:

> [`override` and `final`] have a special meaning when appearing in a certain context. (...) Unless otherwise specified, any ambiguity as to whether a given *identifier* has a special meaning is resolved to interpret the token as a regular *identifier*.

§[class.mem.general] lists the grammar for a class declaration, where `override` only has a special meaning when appearing after the declarator. It's a bit too long to reproduce here, but in all cases except for the last one in the declaration of `Derived::f`, `override` is a normal identifier, used for the *type* `override`.

If we replace the type name `override` with `type`, the definition of `Derived::f` becomes easier to read:

```
virtual auto f() -> type override{
    std::cout << "1";
    return type();
}
```

In `main`, we create an object of type `Derived`, call `f()` on it, and `1` is printed.