§[temp.res]¶1 states:

> A name that appears in a declaration `D` of a template `T` is looked up from where it appears in an unspecified declaration of `T` that either is `D` itself or is reachable from `D` and from which no other declaration of `T` that contains the usage of the name is reachable. If the name is dependent (as specified in 13.8.3), it is looked up for each specialization (after substitution) because the lookup depends on a template parameter.

The first call to `adl` is a non-dependent call, so it is looked up as if at the definition of the function template. The resolution of the second call is deferred until the template is instantiated because it depends on a template parameter.

    template<typename T> void call_adl_function(T t)
    {
        adl(S()); // Independent, looks up adl now.
        adl(t); // Dependent, looks up adl later.
    }

When `adl` is being looked up as if at the definition of the function template, the only version of `adl` that exists is the templated `adl(T)`. Specifically, `adl(S)` does not exist yet, and is not a candidate. 

Note: At the time of writing, this program does not confirm to the standard in some recent versions of Visual Studio's C++ compiler.