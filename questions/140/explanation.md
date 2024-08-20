This question compares three ways for a function to take an array as parameter, but two of them are actually the same.

In `main`, the `array` object is of array type, therefore the `sizeof` operator returns the size of the array in terms of bytes. §[expr.sizeof]¶2:
> When applied to an array, the result is the total number of bytes in the array. This implies that the size of an array of *n* elements is *n* times the size of an element.

In `get_size_1`, `arr` is a pointer to `int`, therefore the `sizeof` operator returns the size of the pointer. §[expr.sizeof]¶1:

> The sizeof operator yields the number of bytes occupied by a non-potentially-overlapping object of the type of its operand.

In `get_size_2`, `arr` is in fact also a pointer to `int`. It looks like an array, but §[dcl.fct]¶5 says:
> (...) any parameter of type “array of `T`” or of function type `T` is adjusted to be “pointer to `T`”

So this case is the same as `get_size_1`, and the size of the pointer is returned again.

In `get_size_3`, `arr` is a reference to an array of size `10`, therefore the `sizeof` operator returns the size of the array in terms of bytes, just like in main. §[expr.sizeof]¶2:
> When applied to a reference or a reference type, the result is the size of the referenced type.

The referenced type is an array of `10` `int`, and as we saw above, §[expr.sizeof]¶2:
> When applied to an array, the result is the total number of bytes in the array.
