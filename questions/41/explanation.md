§[expr.sub]¶2 in the standard says "The expression E1[E2] is identical (by definition) to *((E1)+(E2))".

In our case `1["ABC"]` is identical to `*(1+"ABC")`. Since the plus operator is commutative, this is identical to `*("ABC"+1)`, which is identical to the more familiar `"ABC"[1]`.