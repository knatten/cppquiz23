The goal of this question is to demonstrate that the evaluation order of elements in an initializer list is specified (as opposed to the arguments to a function call).

§[dcl.init.list]¶4: Within the initializer-list of a braced-init-list, the initializer-clauses, including any that result from pack expansions, are evaluated in the order in which they appear.

If `h` took two `int`s instead of a `vector<int>`, and was called like this:
`h(f(), g());`
the program would be unspecified, and could either print `fg` or `gf`.