Even though these constructor invocations look strikingly similar, the one that takes a C-style string and the one that takes a `basic_string` behave differently with respect to the second argument. For the former, it means "until this position", but for the latter it means "from this position".

### Details:

In the constructor taking a C-style string (the `s1` case) the second argument is treated as how many characters to take from the start of the C-style string.  §[string.cons]¶14:

> `constexpr basic_string(const charT* s, size_type n, const Allocator& a = Allocator());`
>
> *Effects*: Constructs an object whose initial value is the range `[s, s + n)`.

On the other hand, in the constructor that takes `basic_string` (the `s2` case) the second argument is treated as the position to *start* copying the string from.  §[string.cons]¶5:

> `constexpr basic_string(const basic_string& str, size_type pos, const Allocator& a = Allocator());`
>
> (...)
>
> Let
> 
> — `s` be the value of `str` prior to this call and
>
> — `rlen` be `pos + min(n, s.size() - pos)` for the overloads with parameter `n`, and `s.size()` otherwise.
>
> *Effects*: Constructs an object whose initial value is the range `[s.data() + pos, s.data() + rlen)`.
