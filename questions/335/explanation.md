§[support.types.nullptr]¶2:

> The macro `NULL` is an implementation-defined null pointer constant.

§[conv.ptr]¶1:

> A *null pointer constant* is an integer literal (§[lex.icon]) with value zero or a prvalue of type `std::nullptr_t`.

In most implementations, `NULL` will be an integer literal and the program will not compile due to ambiguous call `f(NULL)`. However, the C++ standard allows `NULL` to be a prvalue of `std::nullptr_t` in which case the program would output `122`.

Here is [an example](https://www.godbolt.org/z/hY5Trfrc7) where GCC and Clang use `long` for `NULL`, and MSVC uses `int`.