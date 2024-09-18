This program has no output.

`X x();` is a function prototype, not a variable definition. Remove the parentheses (or since C++11, replace them with `{}`), and the program will output `X`.