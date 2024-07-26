`f` takes two template parameters, `T` and `U`, and prints out whether they are the same type. We then call `f` three times, each time with an `int i` and a `double d`.

In the case of `f(i, d)`, both template arguments are deduced. Since `i` is an `int`, `T` is deduced to `int`, and since `d` is a `double`, `U` is deduced to `double`. The types are different, and `0` is printed.

For the two next calls, we explicitly specify a template argument. §[temp.arg.explicit]¶1:
> Template arguments can be specified when referring to a function template specialization

and §[temp.arg.explicit]¶4:
> Trailing template arguments that can be deduced (...) may be omitted from the list of explicit template-arguments.

So we're allowed to explicitly specify some template arguments, and the one(s) we didn't specify are deduced as normal.

In the case of `f<int>(i, d)`, we specify the type of `T` as `int`. The type of `U` is deduced as before to `double`. The types are different, and `0` is printed.

In the case of `f<double>(i, d)`, we specify the type of `T` as `double`. The type of `U` is deduced as before to `double`. The types are the same, and `1` is printed.

Note: in the latter case, `i` needs to be implicitly converted to a double. Aren't implicit conversions disallowed with templates? Only if they participate in template argument deduction. §[temp.arg.explicit]¶7:
> Implicit conversions will be performed on a function argument to convert it to the type of the corresponding function parameter if the parameter type contains no template-parameters that participate in template argument deduction.
>
> [Note 3: Template parameters do not participate in template argument deduction if they are explicitly specified

`T` did not participate in template argument deduction (since `T` was explicitly specified as `double`), so the implicit conversion is allowed.