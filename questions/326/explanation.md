Normally we forward-declare classes when they're used in their pointer or reference form. A forward-declared class is called an *incomplete type*. The question is whether we need a complete type to use it as a parameter or return type for a function declaration.

We do not, the complete type is only required for the function *definition* and for actually calling the function.

For function definitions we have §[dcl.fct.def.general]¶2:

> The type of a parameter or the return type for a function definition shall not be a (possibly cv-qualified) class type that is incomplete or abstract within the function body unless the function is deleted (§[dcl.fct.def.delete]).

For calling functions we have §[expr.call]¶6:

> When a function is called, the type of any parameter shall not be a class type that is either incomplete or abstract.

There is however no such requirement for function declarations.