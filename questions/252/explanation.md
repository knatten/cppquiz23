`'3'` and `'2'` are both ordinary character literals, with type `char`. But we don't know which values they have! That's up to the implementation:

§[lex.ccon]¶3.1:

> A *character-literal* with a *c-char-sequence* consisting of a single *basic-c-char*, *simple-escape-sequence*, or *universal-character-name* is the code unit value of the specified character as encoded in the literal's associated character encoding.

`operator-` subtracts the value of the second operand from the value of the first operand. But how can we know what the result is, when we don't know the values of the operands?

§[lex.charset]¶9:

> The code unit value of each decimal digit character after the digit `0` (U+0030) shall be one greater than the value of the previous.

So we know that the difference between `'3'` and `'2'` is `1`, even if we don't know their actual values. Importantly, this is only true for decimal digits, and not for instance for regular letters. There is no guarantee that `'b' - 'a'` is `1`.