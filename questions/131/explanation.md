These are two examples of initialization. The first form, `C c1(7)`, is called direct-initialization, the second, `C c2 = 7`, is called copy-initialization. In most cases they are equivalent, but in this example they are not, since the `int` constructor is `explicit`.

§[over.match.ctor]¶1:

> When objects of class type are direct-initialized, copy-initialized from an expression of the same or a derived class type ([dcl.init]), or default-initialized, overload resolution selects the constructor. For direct-initialization or default-initialization that is not in the context of copy-initialization, the candidate functions are all the constructors of the class of the object being initialized.

So for the first case (direct-initialization), both the constructors are considered, and the one taking an `int` is a better match.

The paragraph continues:

> For copy-initialization (including default initialization in the context of copy-initialization), the candidate functions are all the converting constructors ([class.conv.ctor]) of that class.

And what is a converting constructor? §[class.conv.ctor]¶1:

> A constructor that is not explicit specifies a conversion from the types of its parameters (if any) to the type of its class. Such a constructor is called a *converting constructor*.

So for the second case (copy-initialization), the explicit constructor taking an `int` is not even considered. Instead, a standard conversion sequence is used to convert the integer literal to a `double`, and the constructor taking a `double` (the only candidate) is used.