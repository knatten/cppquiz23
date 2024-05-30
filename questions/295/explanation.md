This demonstrates the lifetime of temporary objects, and a potential pitfall, especially when refactoring.

Let's look at `main()` one line at a time:

`a_string s1 = make_string();` creates an `a_string`, and `a` is set to `1`. This object is not destroyed (and `a` set back to `0` again) until at the very end of `main()`, after we're done printing.

Then `print(s1.c_str());` is called, printing the value of `a`,  which is now `1`.

Next, we do `const char* s2 = make_string().c_str();`. The temporary `a_string` created by the call to `make_string` sets `a` to `1`, but then back to `0` again when it is destroyed. By the time we get to ` print(s2);`, it prints `0`. Had this been a real `std::string`, ` print(s2);` would cause undefined behavior since `s2` is an invalid pointer!

In `print(make_string().c_str());` the temporary object is instead destroyed _after_ the call to `print` returns, so `1` is printed.

§[class.temporary]¶4 in the standard: "Temporary objects are destroyed as the last step in evaluating the full-expression (§4.k) that (lexically) contains the point where they were created."