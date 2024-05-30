`A::x` and `B::x` actually refer to the same variable, and `int x;` is a definition, not a declaration. Defining the same variable twice results in a compilation error.

Why do `A::x` and `B::x` refer to the same variable?

§[dcl.link]¶6 in the C++ standard:
"Two declarations for a variable with C language linkage with the same name (ignoring the namespace names that qualify it) that appear in different namespace scopes refer to the same variable."

Now, why is `int x;` a definition, and not an `extern` declaration? The standard declares that "a declaration directly contained in a linkage-specification is treated as if it contains the extern specifier". `x` is not directly contained in the linkage specification, and thus doesn't have the implicit `extern`. Therefore it's a definition and repeated definition of `x` causes a compilation error.

§[dcl.link]¶7 in the standard has the explanation and a relevant example:
"A declaration directly contained in a linkage-specification is treated as if it contains the extern specifier (10.1.1) for the purpose of determining the linkage of the declared name and whether it is a definition. (...) [ Example:

    (...)
    extern "C" int i;                   // declaration
    extern "C" {
      int i;                            // definition
    }
    (...)

 — end example ]"

Note: This question is identical to [#191](http://cppquiz.org/quiz/question/191) except for the `{}` surrounding `int x;`. How does this affect the outcome?
