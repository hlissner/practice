#!/usr/bin/env python

from sys import argv
from math import sqrt

def isprime(n):
    if n % 2 == 0:
        return False
    for i in range(3, int(sqrt(n))+1, 2):
        if n % i == 0:
            return False
    return True

def primes(n):
    for i in range(3, n, 2):
        if isprime(i):
            yield i

for test in open(argv[1], 'r'):
    m = int(test.strip())
    if m > 2:
        s = "2"
        for p in primes(m):
            s += "," + str(p)
        print s
