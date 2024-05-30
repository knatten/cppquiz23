You can only get a future from a promise once. Trying to get it again throws `future_­error`.

§[futures.promise]¶13: 

> `future<R> get_future();`
>
> *Throws*: `future_­error` if `*this` has no shared state or if `get_­future` has already been called on a promise with the same shared state as `*this`.

`*this` of course has the same shared state as itself, so the second time we call `get_future`, an exception of type `future_error` is thrown. This exception is then caught, and we print `2`.