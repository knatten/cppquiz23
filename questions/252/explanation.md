`'3'` and `'2'` are both ordinary character literals, with type `char`. But we don't know which values they have! That's up to the implementation:

§[lex.ccon]¶2:
> An ordinary character literal that contains a single *c-char* representable in the execution character set has type `char`, with value equal to the numerical value of the encoding of the *c-char* in the execution character set.

`operator-` subtracts the value of the second operand from the value of the first operand. But how can we know what the result is, when we don't know the values of the operands?

§[lex.charset]¶3:
> In both the source and execution basic character sets, the value of each character after `0` in the above list of decimal digits shall be one greater than the value of the previous.

(The "above list of decimal digits" is simply `0123456789`.)

So we know that the difference between `'3'` and `'2'` is `1`, even if we don't know their actual values. Importantly, this is only true for decimal digits, and not for instance for regular letters. There is no guarantee that `'b' - 'a'` is `1`.