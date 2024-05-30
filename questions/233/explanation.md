§[dcl.fct]¶8 says:

> The return type, the parameter-type-list, the ref-qualifier, the cv-qualifier-seq, and the exception specification, but not the default arguments, are part of the function type.

This means that the ref-qualifier (in this case `const&&`) is part of the type and thus the type of `ptr` is `int(X::*)() const&&`.