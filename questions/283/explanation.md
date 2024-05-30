The core of the question is "in what order are the objects destroyed?". In C++, objects are generally destroyed in the reverse order that they were constructed. `delete[]` is no exception.

§[expr.delete]¶6:
> In the case of an array, the elements will be destroyed in order of decreasing address (that is, in reverse order of the completion of their constructor (...).

So the objects are destroyed in the order `2`, `1`, `0`, and `210` is printed.