The name `f` is overloaded by the two function templates `void f(T)` and `void f(T*)`. Note that overload resolution only considers the function templates, not the explicit specialization `void f<>(int*)`! For overload resolution, first we deduce the template arguments for each function template, and get `T = int *` for the first one, and `T = int` for the second.

Both function templates are viable, but which one is best? According to §[over.match.best]¶2, a function template is a better match than another function template if it's more specialized:

> (...) a viable function `F1` is defined to be a *better* function than another viable function `F2` if (...) the function template for `F1` is more specialized than the template for `F2` according to the partial ordering rules described in §[temp.func.order] (...)

The process of partial ordering is a bit long to quote here, and not key to this question. But in summary, anything accepted by `f(T*)` would also be accepted by `f(T)`, but not the other way around. So `f(T*)` is more specialized.

Now we know that the function template `void f(T*)` is selected by overload resolution, and we can start thinking about specializations. Which of the function templates is `void f<>(int*)` a specialization of? §[temp.expl.spec]¶4:

> A declaration of a function template (...) being explicitly specialized shall be reachable from the declaration of the explicit specialization.

So the explicit specialization `void f<>(int*)` is a specialization of `void f(T)`, since that's the only function template declaration that precedes it. Overload resolution however selected the other function template, `void f(T*)`, and we instead call an implicitly instantiated specialization of that, printing `3`.

*Note: This example is taken from [Why Not Specialize Function Templates?](https://web.archive.org/web/20240427164422/http://www.gotw.ca/publications/mill17.htm) by Herb Sutter.*