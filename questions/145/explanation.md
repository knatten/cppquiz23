In `f()`, an `E` object is constructed, and `1` is printed. This object is then returned to `main()`, and one could expect the copy constructor to be called, printing `2`.

However, `E()` is a prvalue and as such does not constitute an object just yet by §[basic.lval]¶1 

> A prvalue is an expression whose evaluation initializes an object or a bit-field, or computes the value of the operand of an operator, as specified by the context in which it appears.

A prvalue only creates a temporary when needed, for instance to create an xvalue. In those cases, a temporary materialization conversion happens (§[conv.rval]¶1). In this case however, no temporary is needed, and none is created.

§[stmt.return]¶2 says:

> (...) the return statement initializes the returned reference or prvalue result object of the
(explicit or implicit) function call by copy-initialization (9.4) from the operand.

And copy-initialization for a class-type by §[dcl.init]¶17 goes through:

> If the initializer expression is a prvalue and the cv-unqualified version of the source type is the same class as the class of the destination, the initializer expression is used to initialize the destination object.

Which means that no copy or move constructor is called at all. This implies that the copy and move constructor could very well be deleted, and the code would still compile just fine.

The output is thus `13` because of the constructor followed by the destructor call.
