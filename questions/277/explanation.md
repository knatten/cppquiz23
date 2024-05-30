`""` is not completely empty, it has a terminating `\0`:

§[lex.string]¶14:

> `\0` is appended to every string literal so that programs that scan a string can find its end.

Now what's the type of `""`? §[lex.string]¶6 and ¶8:

> a string-literal that does not begin with an encoding-prefix is an ordinary string literal, and is initialized with the given characters.

> Ordinary string literals (...) are also referred to as narrow string literals. A narrow string literal has type “array of `n const char`”, where `n` is the size of the string as defined below

So the type of `""` is “array of `n const char`”. Its size is defined in §[lex.string]¶15:

> The size of a narrow string literal is the total number of escape sequences and other characters, plus at least one for the multibyte encoding of each *universal-character-name*, plus one for the terminating `\0`.

There are no escape sequences, no other characters and no *universal-character-name*s (unicode `U...` constructs), so the size of the array is just 1 for the implicit terminating `\0`.

Finally, what does `sizeof` return when applied to an array?

§[expr.sizeof]¶2:

> When applied to an array, the result is the total number of bytes in the array. This implies that the size of an array of n elements is n times the size of an element.

Our array is 1 elements long, so it returns 1 times the size of the element. How big is the element? §[expr.sizeof]¶1:

> `sizeof(char)`, `sizeof(signed char)` and `sizeof(unsigned char)` are `1`

So we have one element with size `1`, and the program prints `1`.