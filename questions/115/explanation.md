According to §[lex.fcon]¶1 in the standard:

> The type of a *floating-point-literal* (§[basic.fundamental], §[basic.extended.fp]) is determined by its *floating-point-suffix* as specified in Table 11.

And Table 11 maps floating-point-suffix "none" to "double".

The best overload is therefore `void f(double)`.