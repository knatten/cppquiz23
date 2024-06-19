Unsigned integers have well defined behaviour when they overflow. When you go one above the largest representable unsigned int, you end up back at zero.

According to §[basic.fundamental]¶2 in the C++ standard: 
> The range of representable values for the unsigned type is 0 to 2N − 1 (inclusive); arithmetic for the unsigned type is performed modulo 2N .
