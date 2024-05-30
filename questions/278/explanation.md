`std::get<T>(tuple)` can only be used on a tuple which has exactly one `T` in it.

§[tuple.elem]¶5:

    template <class T, class... Types>
    constexpr const T& get(const tuple<Types...>& t) noexcept;

> *Requires:* The type `T` occurs exactly once in `Types....` Otherwise, the program is ill-formed.