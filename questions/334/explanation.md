This is not a compilation error, but undefined behaviour. According to §[stmt.return]¶2 in the standard:

> Flowing off the end of a constructor, a destructor, or a function with a cv `void` return type is equivalent to a `return` with no operand. Otherwise, flowing off the end of a function other than `main` results in undefined behavior.