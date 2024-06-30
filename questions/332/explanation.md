Two consecutive square brackets are normally used for `[[attributes]]`, and indeed we are not allowed to use them like this here. §[dcl.attr.grammar]¶7 in the standard says:

> Two consecutive left square bracket tokens shall appear only when introducing an *attribute-specifier* or within the *balanced-token-seq* of an *attribute-argument-clause*. 

and even gives a similar example.