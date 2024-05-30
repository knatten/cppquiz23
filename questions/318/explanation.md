In this program, the object `s` is converted to `void` in three ways. First with a C-style cast, then with a `static_cast`, and finally by manually calling the conversion function. 

According to the C++ standard, conversion functions will never be used to convert an object to void. So the conversion function is only called once, when we manually call it on the line `s.operator void();`.

§[class.conv.fct]¶1:
> A conversion function is never used to convert a (possibly cv-qualified) object to the (possibly cv-qualified) same object type (or a reference to it), to a (possibly cv-qualified) base class of that type (or a reference to it), or to (possibly cv-qualified) void