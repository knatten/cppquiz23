Here we have three calls to `f`. Which function is selected for each call? §[temp.over]¶1 is surprisingly readable:
> A function template can be overloaded either by (non-template) functions of its name or by (other) function templates of the same name. 

The function template `f` is in our case overloaded by the non-template `void f(int)`. It goes on:
> When a call to that name is written [...], template argument deduction [is] performed for each function template to find the template argument values (if any) that can be used with that function template to instantiate a function template specialization that can be invoked with the call arguments

So in the tree cases above, we first do template argument deduction, giving `double`, `int` and `int`, respectively.

Then:
> For each function template, if the argument deduction and checking succeeds, the template-arguments [...] are used to synthesize the declaration of a single function template specialization which is added to the candidate functions set to be used in overload resolution

So in all the three cases above, a specialization of the function template `f` is added to the candidates to overload resolution, with `T` equal to `double`, `int` and `int`, respectively.

Now look at each call:

For `f(0.0)`, `T` is deduced as `double`, and a specialization `void f(double)` is added as a candidate for overload resolution. The other candidate is the non-template function `void f(int)`. The one taking a `double` is a better match, and `1` is printed.

For `f(0)`, `T` is deduced as `int`, and a specialization `void f(int)` is added as a candidate for overload resolution. The other candidate is the non-template function `void f(int)`. Both are equally good matches, so is the program ill-formed?

§[over.match.best]¶1>
> F1 is defined to be a better function than another viable function F2 if [...]
> F1 is not a function template specialization and F2 is a function template specialization

`void f(int)` is not a function template specialization, and `template<> void f(int)` is, so the former is selected, and `3` is printed.

Finally we get to `f<>(0)`. `<>` is an (empty) template argument list, which can be specified for template functions, but not for non-template functions. So in this case, the non-template function is not an option, we explicitly ask for the function template. This is also described in a note in §[temp.arg.explicit]¶4:
> An empty template argument list can be used to indicate that a given use refers to a specialization of a function template even when a non-template function is visible that would otherwise be used.

`T` is deduced to `int`, the specialization for `int` is the only candidate, and `2` is printed.