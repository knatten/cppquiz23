Although this program probably outputs `8` on your computer, it's not guaranteed to do so by the standard. All we can be sure of is that it's _at least_ 8 bits.

Table 14 in §[basic.fundamental] specifies the size of `signed char` as 8. But we're interested in `unsigned char`, not `signed char`.

§[basic.fundamental]¶3 however explains that an unsigned type is similar to the corresponding signed type:

>  An unsigned integer type has the same object representation, value representation, and alignment requirements (6.7.6) as the corresponding signed integer type.

So `unsigned char` is the same size as `signed char`, which is at least 8 bits.
