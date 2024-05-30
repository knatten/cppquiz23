First, `b1` is default initialized. All members are initialized before the body of the constructor, so `b1.a` is default initialized first, and we get the output `14`.

§[class.base.init]¶9 in the standard: "In a non-delegating constructor, if a given potentially constructed subobject is not designated by a
mem-initializer-id (...) then if the entity is a non-static data member that has a default member initializer (§ 12.2), (...) the entity is initialized as specified in § 11.6 (...) otherwise, **the entity is default-initialized.**"

Then, `b2` is initialized with the move construcor (since `std::move(b1)`converts the reference to `b1` to an xvalue, allowing it to be moved from.) In `B`'s move constructor, `a` is initialized in the member initializer list. Even though `b` is of type rvalue reference to `B`  (and bound to an rvalue), the expression `b` is an lvalue. Lvalues cannot be moved from, so `b2.a` is copy initialized, printing `2`. Finally the body of `B`'s move constructor prints `6`.

(If the concept of rvalue references being lvalues is confusing, read <http://isocpp.org/blog/2012/11/universal-references-in-c11-scott-meyers> . Search for "In widget".)