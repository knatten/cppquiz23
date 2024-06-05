Static members of class templates like `C::printer` are only instantiated if they are used in a way that requires them to be defined. `C::printer` is not used at all in this program, so it is never initialized, and `1` is never printed.

§[temp.inst]¶4:

> Unless a member of a templated class is a declared specialization, the specialization of the member is implicitly instantiated when the specialization is referenced in a context that requires the member definition to exist or if the existence of the definition of the member affects the semantics of the program; in particular, the initialization (and any associated side effects) of a static data member does not occur unless the static data member is itself used in a way that requires the definition of the static data member to exist.