As defined in §[basic.scope.pdecl]¶1, the point of name declaration is after its
complete declarator and before its initialisation. This
means that line 4 is valid C++, because it's possible
to initialise the variable `p` with the address of an existing
variable, even if it is its own address.

The value of `p` is unknown, but can not be a null pointer value. The
cast must thus evaluate to 1 and initialise the temporary
bool as true.
