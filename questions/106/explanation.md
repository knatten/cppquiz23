According to §[dcl.link]¶7 in the standard : A declaration directly contained in a linkage-specification is treated as if it contains the extern specifier for the purpose of determining the linkage of the declared name and whether it is a definition.
    extern "C" int x; // is just a declaration
    extern "C" { int y; } // is a definition

And according to  §[basic.def.odr]¶4: "Every program shall contain exactly one definition of every non-inline function or variable that is odr-used in that program outside of a discarded statement; no diagnostic required."

The result: `x` is never defined but it is optional for the compiler to print an error. The behaviour of this program is undefined.