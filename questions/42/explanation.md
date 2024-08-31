`a1` is default initialized, as described in §[dcl.init.general]¶12.

`a2` doesn't actually use the initializer_list constructor with a list of zero elements, but the default constructor:
§[dcl.init.list]¶3:
List-initialization of an object or reference of type T is defined as follows:
- (...)
- Otherwise, if the initializer list has no elements and T is a class type with a default constructor, the object is value-initialized.
- Otherwise, if T is a specialization of std::initializer_list<E>, the object is constructed as described below.

`a3`'s and `a4`'s constructor is chosen in overload resolution, as described in §[over.match.list]:

"When objects of non-aggregate class type T are list-initialized (...), overload resolution selects the constructor in two phases:
— If the initializer list is not empty or T has no default constructor, overload resolution is first performed where the candidate functions are the initializer-list constructors (§[dcl.init.list]) of the class T and the argument list consists of the initializer list as a single argument.
— Otherwise, or if no viable initializer-list constructor is found, overload resolution is performed again, where the candidate functions are all the constructors of the class T and the argument list consists of the elements of the initializer list."

Initializer list constructors are greedy, so even though `A(int)` constructor is available, the standard mandates that `initializer_list<int>` is prioritized, and if - and only if - it's not available, the compiler is allowed to look for other constructors. (This is why it is not recommended to provide a constructor that ambiguously overloads with an initializer_list constructor. See the answer to #4 in <https://herbsutter.com/2013/05/09/gotw-1-solution/>.)