The compilation error is on the line `y.f()`, but the source of the problem is `Y y(X());`

This could be interpreted as a variable definition (which was the intention of the programmer in this example), or as a declaration of a function `y`, returning an object of type `Y`, taking a function (with no arguments, returning an object of type `X`) as its argument.

The compiler is required by the standard to choose the second interpretation, which means that `y.f()` does not compile (since `y` is now a function, not an object of type `Y`).

Wikipedia has a concise explanation: <http://en.wikipedia.org/wiki/Most_vexing_parse>, and the standard has more in §[stmt.ambig].

To fix the problem, change `Y y(X())` to either `Y y{X{}}` (modern C++) or `Y y((X()))` (pre-C++11)