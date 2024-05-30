Perhaps surprisingly, this program has no undefined behaviour. `std::string`'s `operator[](size_type pos)` must return a reference to the null character when `pos` equals the length of the string:

§[string.access]¶2:
> `const_reference operator[](size_type pos) const;`
> `reference       operator[](size_type pos);`
>
> *Requires*: pos <= size().
>
> *Returns*: `*(begin() + pos)` if `pos < size()`. Otherwise, returns a reference to an object of type `charT` with value `charT()`, where modifying the object to any value other than `charT()` leads to undefined behavior.

`charT()` is `char()` in this case. The `char()` expression value-initializes a `char`, which initializes it to `0`.

So `out[out.size()] == '\0'` compares `0` to `\0`. Are they the same? Yes:

§[lex.charset]¶3:
> The basic execution character set and the basic execution wide-character set shall each contain all the members of the basic source character set, plus control characters representing alert, backspace, and carriage return, plus a null character (respectively, null wide character), whose value is `0`

So the value of `\0` is indeed `0`. The comparison is true, and `1` is printed.