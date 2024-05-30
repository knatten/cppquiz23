There are two exception handlers, `exception& e` and `out_of_range& e`. Both would be appropriate handlers for an `out_of_range` exception, since `out_of_range` inherits from `exception`.

How is the the handler selected? §[except.handle]¶4:
> The handlers for a try block are tried in order of appearance. [ Note: This makes it possible to write handlers that can never be executed, for example by placing a handler for a final derived class after a handler for a corresponding unambiguous public base class. — end note ]

The note in the standard hints at what's happening here: Even if  `out_of_range& e` is a more specific match, `exception& e` matches before we even get to try it, and `1` is printed.