C++ provides alternative tokens for some punctuators. The two weird lines are exactly equivalent to 

    int a[] = {1};
    std::cout << a[0];

§[lex.digraph]¶1 in the C++ standard explains this:

"Alternative token representations are provided for some operators and punctuators."
§[lex.digraph]¶2
"In all respects of the language, each alternative token behaves the same, respectively, as its primary token, except for its spelling."

Then, a table of alternative tokens is provided, which includes
- `<%` and `%>` for `{` and `}`
- `<:` and `:>` for `[` and `]`