The first line in `main()`, `X x;` is straightforward, it calls the default constructor.

The next two lines is the heart of the question: The difference between `X y(x)` and `X z = y` is not that the first calls the copy constructor, and the second calls the copy assignment operator. The difference is that the first is direct-initialization (§[dcl.init.general]¶15 in the standard) and the second is copy-initialization (§[dcl.init.general]¶14).

§[dcl.init.general]¶16.6.2:

> Otherwise, if the initialization is direct-initialization, or if it is copy-initialization where the cv-unqualified version of the source type is the same class as (...) the class of the destination, constructors are considered.

So both our cases use the copy constructor.

Not until `z = x;` do we have an actual assignment that uses the assignment operator.

See <https://stackoverflow.com/a/1051468> for a more detailed discussion of direct- vs copy-initialization.