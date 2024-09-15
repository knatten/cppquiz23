`f` in the function call `f()` is unqualified and non-dependent, so unqualified name lookup takes place when the template definition is examined, skipping the dependent base class `B` and binding the name to the global declaration of `f`. See discussions in [the C++ FAQ](https://isocpp.org/wiki/faq/templates#nondependent-name-lookup-members) and on [Stack Overflow](https://stackoverflow.com/questions/4643074/why-do-i-have-to-access-template-base-class-members-through-the-this-pointer).

#### Detailed explanation:

First, notice that the name `f` is unqualified. §[basic.lookup.unqual]¶4:

> An *unqualified name* is a name that does not immediately follow a *nested-name-specifier* or the `.` or `->` in a class member access expression (§[expr.ref]), possibly after a `template` keyword or `~`. Unless otherwise specified, such a name undergoes unqualified name lookup from the point where it appears.

What does unqualified name lookup mean? §[basic.lookup.unqual]¶3:

> *Unqualified name lookup* from a program point performs an unqualified search in its immediate scope.

The definition of an unqualified search is given in §[basic.lookup.unqual]¶2:

> An *unqualified search* in a scope *S* from a program point *P* includes the results of searches from *P* in
>
> — *S*, and
>
> — for any scope *U* that contains *P* and is or is contained by *S*, each namespace contained by *S* that is nominated by a *using-directive* that is active in *U* at *P*.
>
> If no declarations are found, the results of the unqualified search are the results of an unqualified search in the parent scope of *S*, if any, from *P*.

Since we don't have any using-directives, we search for `f` in its immediate scope, which is a block scope of function `g` per §[basic.scope.scope]¶1. And if we don't find any result, we keep searching in parent scopes (§[basic.scope.scope]¶2.1), recursively. But what does the term "search" mean anyway? §[class.member.lookup]¶1:

> A *search* in a scope *X* for a name *M* from a program point *P* is a single search in *X* for *M* from *P* unless *X* is the scope of a class or class template *T*, in which case the following steps define the result of the search.

The definition of a single search is given in §[basic.lookup.general]¶3:

> A *single search* in a scope *S* for a name *N* from a program point *P* finds all declarations that precede *P* to which any name that is the same as *N* (§[basic.pre]) is bound in *S*.

Basically, that means that we look for any declaration of `f` that appears in `g` before the call. We don't find any, so we continue our unqualified search in a parent scope, which is a class scope introduced by the declaration of the class template `D`. As we saw in §[class.member.lookup]¶1, there are special rules for searching in class templates. The rules are lengthy, but the key points are:

§[class.member.lookup]¶3:

> The declaration set is the result of a single search in the scope of *C* for *N* from immediately after the *class-specifier* of *C* if *P* is in a complete-class context of *C* (...). If the resulting declaration set is not empty, the subobject set contains *C* itself, and calculation is complete.

§[class.member.lookup]¶4:

> Otherwise (...), *S*(*N*,*C*) is initially empty. Calculate the lookup set for *N* in each direct non-dependent (§[temp.dep.type]) base class subobject *B<sub>i</sub>*, and merge each such lookup set *S*(*N*,*B<sub>i</sub>*) in turn into *S*(*N*,*C*).

So, instead of just a single search in a class scope from some program point, we perform a single search in a class scope from the end of that class definition, and if that search fails, we continue in its non-dependent base classes. In our case, we don't find any declaration of `f` in the class `D`, and we don't continue in `B` because `B<T>` is dependent on the template parameter `T`.

§[temp.dep.type]¶3:

> A *dependent base class* is a base class that is a dependent type and is not the current instantiation.

§[temp.dep.type]¶7:

> A type is dependent if it is
>
> — a template parameter,
>
> — (...)
>
> — denoted by a *simple-template-id* in which (...) any of the template arguments is a dependent type (...)

(If we were to call `f` using a dependent name (e.g., via `this->f()`), the lookup would happen at the point of the template instantiation (§[temp.res.general]¶1), which would cause the base class to be non-dependent (§[class.member.lookup]¶note-2).)

Finally, we continue our unqualified search in the global scope, find the declaration of `f` there, and output `1`.

#### Note:

In practice, not all compilers obey these rules, and some of them produce (erroneously) the code that outputs `2`. For example, GCC 14.2 - `1`, Clang 18.0.1 - `1`, Microsoft C++ 19.40 - `2`, Intel C++ 15.0.7.287 (On Windows) - `2`. Even if the implementation you use calls `B::f()` for the unqualified `f()`, you should **not** rely on this behavior.