§[temp.fct.spec]¶2: Each function template specialization instantiated from a template has its own copy of any static variable.

This means we get two instantiations of `f`, one for `T`=`int`, and one for `T`=`double`. Thus, `i` is shared between the two `int` calls, but not with the `double` call.
