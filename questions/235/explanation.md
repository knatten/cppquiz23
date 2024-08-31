The class `C` prints `1` when it's copied. But when is it copied?

§[dcl.init.list]¶5 in the standard explains construction of `initializer_list`:
> An object of type `std::initializer_list<E>` is constructed from an initializer list as if the implementation generated and materialized a prvalue of type “array of `N const E`”, where `N` is the number of elements in the initializer list. Each element of that array is copy-initialized with the corresponding element of the initializer list, and the `std::initializer_list<E>` object is constructed to refer to that array.

So when we construct the initializer list `i`, we can imagine a temporary array of one `C` being created, where the element is copy-initialized. Since `c` is an lvalue, a copy is made (not for instance a move), and `1` is printed.

Then, `f` is called twice, taking the freshly created `initializer_list` by value. So a copy of the `initializer_list` is made for each call. Does that make a copy of the elements in the initializer list, as it would when taking for instance a `vector` or a `list` by value? No. As we saw at the end of the quote above:

> the `std::initializer_list<E>` object is constructed to refer to that array.

So the `initializer_list` only refers to that array, it doesn't have a copy of it. A note in §[initializer.list.syn]¶note-1 spells it out verbatim:

> Copying an initializer list does not copy the underlying elements.

The key takeaway is: If you write an initializer list constructor for your class, never move the elements out of the initializer list. Even if you took it by value, you were not passed an exclusive copy of the elements, which might still be used by others.