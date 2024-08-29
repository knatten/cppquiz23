Modifying string literals is undefined behavior. In practice, the implementation can for instance store the string literal in read-only memory, such as the `.rodata` segment on Linux. Two string literals might even be stored in overlapping memory. So allowing them to be modified is clearly not a good idea.

§[lex.string]¶9:

> Whether all string-literals are distinct (that is, are stored in nonoverlapping objects) and whether successive evaluations of a string-literal yield the same or a different object is unspecified.
>
> [Note 4: The effect of attempting to modify a string literal object is undefined. —end note]

Also, §[lex.string]¶1 specifies the type of the string literal as "array of n const char", which means it should not be modified.