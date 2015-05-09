#!/usr/bin/env python

# Checks to see if X is a prime number
#   Usage: python solution.py 10 11 12

import sys

def prime_factors_for(n):
    factors = []
    while not is_prime(n):
        p = next_prime_factor(n, 1)
        factors += [p]
        n /= p
    if len(factors) == 0:
        factors += [1]
    factors += [int(n)]

    return factors

def next_prime_factor(n=500, last=1):
    next_num = last + 1
    if n % next_num == 0 and is_prime(next_num):
        return next_num
    if next_num >= n:
        return False
    return next_prime_factor(n, next_num)

def is_prime(n):
    n = int(n)
    if n == 0:
        return False
    if n <= 2:
        return True
    if n > 10 and (n % 2 == 0 or n % 5 == 0):
        return False
    for i in range(2, n):
        if n % i == 0:
            return False
    return True


argc = len(sys.argv)
if argc > 1:
    for i in sys.argv[1:]:
        print(i, "=", prime_factors_for(int(i)))
else:
    print("Usage {0} [number1] [[number2] ...]")
