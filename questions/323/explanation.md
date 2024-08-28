This is taken from an example in §[except.ctor]¶2 in the standard about stack unwinding:

> Each object with automatic storage duration is destroyed if it has been constructed, but not yet destroyed, since the try block was entered. If an exception is thrown during the destruction of temporaries or local variables for a `return` statement (§[stmt.return]), the destructor for the returned object (if any) is also invoked. The objects are destroyed in the reverse order of the completion of their construction.
>
> [*Example 1*: 
>
> ```
> struct A { };
>
> struct Y { ~Y() noexcept(false) { throw 0; } };
>
> A f() {
>   try {
>     A a;
>     Y y;
>     A b;
>     return {};      // #1
>   } catch (...) {
>   }
>   return {};        // #2
> }
> ```
>
> At #1, the returned object of type `A` is constructed. Then, the local variable `b` is destroyed (§[stmt.jump]). Next, the local variable `y` is destroyed, causing stack unwinding, resulting in the destruction of the returned object, followed by the destruction of the local variable `a`. Finally, the returned object is constructed again at #2. — *end example*]

It is worth noting that at the time of writing, neither GCC, Clang nor MSVC conform to the behaviour described in the standard, and instead print `bacd`, `bad` and `bad`, respectively.