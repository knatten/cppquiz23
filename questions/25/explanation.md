Signed integer overflow is undefined behaviour according to the standard §[expr]¶4: "If during the evaluation of an expression, the result is not mathematically defined or not in the range of representable values for its type, the behavior is undefined."

Most implementations will just wrap around, so if you try it out on your machine, you will probably see the same as if you had done

```
std::cout << std::numeric_limits<int>::min();
```

Relying on such undefined behaviour is however *not* safe. For an interesting example, see <https://stackoverflow.com/questions/7682477/why-does-integer-overflow-on-x86-with-gcc-cause-an-infinite-loop>.