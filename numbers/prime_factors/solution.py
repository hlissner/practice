#!/usr/bin/env python

# Checks to see if each arg is a prime number
#   Usage: python solution.py 10 11 12

import sys
from math import sqrt

def is_prime(n):
    for i in range(2, int(sqrt(n))+1):
        if n % i == 0:
            return False
    return True

def pfactors(n):
    factors = [1]
    if n % 2 == 0:
        factors.append(2)
    for x in range(3, int(sqrt(n))+1, 2):
        if n % x == 0:
            if is_prime(x):
                factors.append(x)
    return factors + [n]


argc = len(sys.argv)
if argc > 1:
    for i in sys.argv[1:]:
        print(pfactors(int(i)))
else:
    print("Usage {0} [number1] [[number2] ...]")
