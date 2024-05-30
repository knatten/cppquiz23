The "trick" here is that `B::f()` is called even though it is private.

As §[class.access.virt]¶2 in the standard puts it: "Access is checked at the call point using the type of the expression used to denote the object for which the member function is called". The call point here being `a.f()`, and the type of the expression is `A&`.
