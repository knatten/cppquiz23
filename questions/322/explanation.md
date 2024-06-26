This is not legal. According to §[except.pre]¶3 in the standard:

> The compound-statement of a try block or of a handler is a control-flow-limited statement (§[stmt.label]).

and via §[stmt.label]¶3:

> A *control-flow-limited statement* is a statement S for which:
>
> — (...)
>
> — a label declared in S shall only be referred to by a statement (§[stmt.goto]) in S.

So this fails to compile.