Perhaps surprisingly, this program has no undefined behaviour. `std::string`'s `operator[](size_type pos)` must return a reference to the null character when `pos` equals the length of the string:

§[string.access]¶2:

> ```
> constexpr const_reference operator[](size_type pos) const;
> constexpr reference       operator[](size_type pos);
> ```
>
> *Preconditions*: `pos <= size()`.
>
> *Returns*: `*(begin() + pos)` if `pos < size()`. Otherwise, returns a reference to an object of type `charT` with value `charT()`, where modifying the object to any value other than `charT()` leads to undefined behavior.

`charT()` is `char()` in this case. The `char()` expression value-initializes a `char`, which initializes it to `0`.

So `out[out.size()] == '\0'` compares a character with value `0` to a character literal `'\0'`. Are they the same?

§[lex.ccon]¶3.2.2:

> A *character-literal* with a *c-char-sequence* consisting of a single *numeric-escape-sequence* has a value as follows:
>
> — Let *v* be the integer value represented by the octal number comprising the sequence of *octal-digit*s in an *octal-escape-sequence* (...).
>
> — If *v* does not exceed the range of representable values of the *character-literal*'s type, then the value is *v*.

According to the grammar (§[lex.ccon]¶nt:octal-escape-sequence), `\0` is an octal escape sequence, so the value of `'\0'` is indeed `0`. The comparison is true, and `1` is printed.