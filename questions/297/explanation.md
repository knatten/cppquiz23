`wait` does not throw exceptions stored in the shared state.

§[futures.unique.future]¶21:

> `void wait() const;`
>
> *Effects*: Blocks until the shared state is ready.

To get at the exception, you have to use `get`. §[futures.unique.future]¶19:

>     R future::get();
>     R& future<R&>::get();
>     void future<void>::get();
>
> *Throws*: the stored exception, if an exception was stored in the shared state.

So there's no exception thrown, the `catch` block is never entered, and the program only prints `2`.