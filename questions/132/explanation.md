Is `foo` called both times or just once? The C++ standard says this in §[dcl.fct.default]¶9: "A default argument is evaluated each time the function is called with no argument for the corresponding parameter."

Thus, `foo` is called twice.
