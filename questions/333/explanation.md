There is no `-->` operator in C++, this is actually the two operators `--` and `>` placed next to each other. Whitespace in C++ is generally not significant, unless absolutely needed to separate adjacent tokens which would otherwise have a different meaning. §[lex.token]¶1 in the standard:

> Blanks, horizontal and vertical tabs, newlines, formfeeds, and comments (collectively, “whitespace”), as described below, are ignored except as they serve to separate tokens.
>
> [*Note 1*: Some whitespace is required to separate otherwise adjacent identifiers, keywords, numeric literals, and alternative tokens containing alphabetic characters. — *end note*]

So this should be read as `while (x-- > 0)`, meaning that `x` is `2` on the first iteration, `1` on the next, and `0` on the last (since we're post decrementing it and comparing the not-yet-decremented value to `0`). The program prints `210`.