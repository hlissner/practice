#!/usr/bin/env python

from sys import argv
from math import sqrt

def isprime(n):
    if n & 1 == 0:
        return False
    for i in range(3, int(sqrt(n))+1, 2):
        if n % i == 0:
            return False
    return True

def primes(n):
    sum = 2
    x = 3
    for i in range(n-1):
        sum += x
        x += 2
        while not isprime(x):
            x += 2
    return sum

print(primes(1000))
