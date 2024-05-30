
### Updating meta data

If the correct answer for a question has changed, you need to update the `meta_data.json` file in the directory for that question. Here's an example:

```
{
    "answer": "1",
    "difficulty": 2,
    "state": "PUB",
    "id": 1,
    "result": "OK"
}
```

The fields you need to care about are `answer` and `result`:

- `answer`: If the program is supposed to compile and output something, put that output here. If not, set it to `""`.
- `result`: Here you need to set the correct shorthand for an enum. The possible values are:
    - `OK`: The program is guaranteed a certain output
    - `CE`: The program has a compilation error
    - `US`: The program is unspecified / implementation defined
    - `UD`: The program has undefined behavior
