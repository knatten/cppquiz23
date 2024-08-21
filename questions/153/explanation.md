According to §[lex.string]¶8 in the standard:

> A narrow string literal has type “array of *n* `const char`”

The array of *n* `const char` decays to a pointer to `const char`. That pointer to `const char` does not implicitly convert to a pointer to non-const `char`.

§[conv.qual]¶note-3 extrapolates from the preceding normative passages:

> A prvalue of type “pointer to *cv1* `T`” can be converted to a prvalue of type “pointer to *cv2* `T`” if “*cv2* `T`” is more cv-qualified than “*cv1* `T`”.

In this case however, `char*` is less cv-qualified than `const char *`, so the conversion is not allowed.

Note: While most compilers still allow `char const[]` to `char*` conversion with just a warning, this is not a legal conversion since C++11.

See also <https://dev.krzaq.cc/stop-assigning-string-literals-to-char-star-already/>