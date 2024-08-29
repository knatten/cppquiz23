There are two alternatives for the call to `f` here, the primary function template, and the explicit specialization. So we need overload resolution to figure out which one to call.

Overload resolution when function templates are involved works like this (summarized from §[temp.over]¶1):
- Do type deduction (or check explicit template arguments) for all function templates
- Add all function templates where this succeeded to the set of candidate functions
- Add all non-template functions of the same name to the set of candidate functions (there are none in this question)
- Do overload resolution on the candidates and pick the best viable function

We start with type deduction:

- For the primary template, `T` is deduced from the call `f(i)` as `int`, and the parameter type is `int &`.
- For the explicit specialization, the parameter type is `const int&`.

Overload resolution now has to find a conversion sequence from the argument `i` to each of the parameter types `int &` and `const int &`, and if one conversion sequence is better, that's the one that's chosen. If neither is better than the other, the call is ill-formed.

Both `int &` and `const int &` can bind directly to `i`, so no conversion is needed in either case. So far there's a tie, but §[over.ics.rank]¶3 has the answer:

> Standard conversion sequence S1 is a better conversion sequence than standard conversion sequence S2 if
- (...)
- S1 and S2 include reference bindings ([dcl.init.ref]), and the types to which the references refer are the same type except for top-level cv-qualifiers, and the type to which the reference initialized by S2 refers is more cv-qualified than the type to which the reference initialized by S1 refers.

The types to which the references refer are `int` for S1 and `const int` for S2. Those are indeed the same types except for top-level cv-qualifiers, and `const int` is indeed more cv-qualified than `int`, so S1 is a better conversion sequence and the primary function template is the best viable function.

The primary function template is thus called, and `1` is printed.