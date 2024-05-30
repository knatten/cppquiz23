`wait` does not throw exceptions stored in the shared state.

§[futures.unique_future]¶20:

> `void wait() const;`
> Effects: Blocks until the shared state is ready.

To get at the exception, you have to use `get`. §[futures.unique_future]¶20:

> `future<R&>::get();`
> *Throws*: the stored exception, if an exception was stored in the shared state.

So there's no exception thrown, the `catch` block is never entered, and the program only prints `2`.