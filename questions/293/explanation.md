You might think we access an out-of-bounds array element and the program behaviour is undefined, but §[basic.start.main]¶2 explicitly states:

> The value of `argv[argc]` shall be 0.