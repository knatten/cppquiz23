`x` is a public member of `B`, which is a base class of `C` and `D`. Which accessibility does `x` have in `C` and `D`?

§[class.access.base]¶1:
> If a class is declared to be a base class (...) for another class using the `public` access specifier, the `public` members of the base class are accessible as `public` members of the derived class(...)
>
> If a class is declared to be a base class for another class using the `private` access specifier, the `public` (...) members of the base class are accessible as `private` members of the derived class

So any public members from `A` (there are none in this example) would be `public` in `C`, and `private` in `D`. But what about `B`, where `x` is defined? Are `C` and `D` deriving publicly or privately from `B` when there is no access-specifier?

§[class.access.base]¶2:
> In the absence of an access-specifier for a base class, `public` is assumed when the derived class is defined with the class-key `struct` and `private` is assumed when the class is defined with the class-key `class`.

So since we don't provide an access-specifier for `B`, `class C` derives privately from `B`, making `x` `private`. And `struct D` derives publicly from `B`, making `x` `public`.

This means the line `c.x = 3` has a compilation error since `x` is `private`.