#!/usr/bin/env python

import sys
import time

# Fast method: O(log n)-ish (depending on the speed of exponent operations. Also
# (theoretically) imprecise
def fast_fib(n):
    p = 5**.5
    a = (1 + p)/2
    b = (1 - p)/2
    return int((a**(n+1) - b**(n+1)) / p)

# Slow method: O(n^2)
def slow_fib(n):
    if n <= 1:
        return 1
    return slow_fib(n-1) + slow_fib(n-2)

argc = len(sys.argv)
if argc > 1:
    print("(Using {0} method)".format("fast" if argc > 2 else "slow"))

    start = time.perf_counter()
    for i in range(int(sys.argv[1])):
        print(fast_fib(i) if argc > 2 else slow_fib(i))
    print("\nDone in: {0:.6f}s".format(time.perf_counter() - start))
else:
    print("Usage: {0} [N]".format(sys.argv[0]))
