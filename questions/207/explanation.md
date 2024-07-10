The `[]` operator inserts an element if the key is not present. For a simple `int`, it inserts `0`.

According to §[map.access]¶2 in the standard:

> `T& operator[](key_type&& x);`
>
> Effects: Equivalent to: `return try_emplace(move(x)).first->second;`

where `try_emplace` is defined by §[map.modifiers]¶4:

> `template <class... Args> pair<iterator, bool> try_emplace(const key_type& k, Args&&... args);`
>
> Effects: If the map already contains an element whose key is equivalent to `k`, there is no effect. Otherwise inserts an object of type value_type constructed with `piecewise_construct, forward_as_tuple(k), forward_as_tuple(std::forward<Args>(args)...)`.

`value_type` is just a `typedef` for `pair<const Key, T>`, which in our case is `pair<const int, int>`. So it inserts a `pair(42, int())`.

`int()` is a *value-initialization*, which for non-class, non-array types means *zero-initialization* (see §[dcl.init]¶8). And according to §[dcl.init.general]¶6:

> To zero-initialize an object or reference of type `T` means:
> — if `T` is a scalar type (§[basic.types.general]), the object is initialized to the value obtained by converting the integer literal `0` (zero) to `T`;

So setting the value for the key `42` to `T()` means setting it to `0`.