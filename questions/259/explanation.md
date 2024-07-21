The type of the sum of two `char`s is actually not uniquely specified. We do however know it's not `char`.

Before being passed to operator `+`, the operands (`x` and `y`) go through a conversion. §[expr.add]¶1:

> The additive operators `+` and `-` group left-to-right. The usual arithmetic conversions are performed for operands of arithmetic or enumeration type.

What are "the usual arithmetic conversions"?

§[expr.arith.conv]¶1.3:

> Many binary operators that expect operands of arithmetic or enumeration type cause conversions and yield result types in a similar way. The purpose is to yield a common type, which is also the type of the result. This pattern is called the *usual arithmetic conversions*, which are defined as follows:
>
> — (...)
>
> — (...). The integral promotion rules (§[conv.prom]) are used to determine a type `T1` and type `T2` for each operand.

So both `char`s go through integral promotions. Those are defined in §[conv.prom]¶1:

> A prvalue of an integer type other than `bool`, `char8_t`, `char16_t`, `char32_t`, or `wchar_t` whose integer conversion rank (§[conv.rank]) is less than the rank of `int` can be converted to a prvalue of type `int` if `int` can represent all the values of the source type; otherwise, the source prvalue can be converted to a prvalue of type `unsigned int`.

(Note that an integral promotion requires an expression to be a prvalue, so our glvalues `x` and `y` are converted to prvalues first via lvalue-to-rvalue conversions as parts of the corresponding standard conversion sequences (§[conv.general]¶1).)

So a `char` gets converted to an `int` if `int` can fit all possible values of a `char`. But that's not necessarily the case!

First, `int` could actually be the same size as `char`. §[basic.fundamental]¶1:

> There are five *standard signed integer types*: “`signed char`”, “`short int`”, “`int`”, “`long int`”, and “`long long int`”. In this list, each type provides at least as much storage as those preceding it in the list.

Note that it says "at least as much storage", it doesn't have to be more. So for instance you could have a sixteen bit system where both `char` and `int` are sixteen bits.

Second, `char` can be either signed or unsigned, it's up to the implementation: §[basic.fundamental]¶7:

> Type `char` is a distinct type that has an implementation-defined choice of “`signed char`” or “`unsigned char`” as its underlying type.

`int` is signed, so if `char` is also signed, all possible values of `char` will fit in an `int`. However, if `char` is unsigned, and `int` and `char` are the same size, `char` can actually hold larger values than `int`! In the former case, `char`s get promoted to `int`s, but in the latter case, `char`s get promoted to `unsigned int`s before being summed.

So in practice, most systems will call `f(int)` and print `i`, but some might call `f(unsigned int)` and print `u`, and they would both be conforming to the standard.