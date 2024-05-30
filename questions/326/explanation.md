Normally we forward declare classes when they're used in their pointer or reference form. A forwarded declared class is called an *incomplete type*. The question is whether we need a complete type to use it as a parameter or return type for a function declaration.

We do not, the complete type is only required for the function *definition* and for actually calling the function. 

For function definitions we have §[expr.call]¶4:
> The type of a parameter or the return type for a function definition shall not be an incomplete (possibly cv-qualified) class type in the context of the function definition unless the function is deleted.

For calling functions we have §[dcl.fct]¶11:
>When a function is called, the parameters that have object type shall have completely-defined object type.

There is however no such requirement for function declarations.