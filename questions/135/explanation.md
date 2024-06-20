`std::map` stores values based on a unique key. The keys for `mb` are boolean, and `1`, `3` and `5` all evaluate to the same key, `true`.

§[map.overview]¶1 in the standard:
> A map is an associative container that supports unique keys (contains at most one of each key value).

The type of `mb` is `map<bool,int>`. The key is bool, so the integers `1`, `3` and `5` used for initialization are first converted to bool, and they all evaluate to true.

§[conv.bool]¶1 in the standard:
> A prvalue of arithmetic, unscoped enumeration, pointer, or pointer to member type can be converted to a prvalue of type bool. A zero value, null pointer value, or null member pointer value is converted to false; any other value is converted to true.
