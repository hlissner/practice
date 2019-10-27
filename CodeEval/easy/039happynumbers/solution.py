#!/usr/bin/env python

from sys import argv

def happy_proc(n):
    sum = 0
    for i in str(n):
        sum += int(i) ** 2
    return sum

for line in open(argv[1]):
    limit = 30
    n = int(line)
    while (n != 1 and limit > 0):
        n = happy_proc(n)
        limit -= 1
    print("1" if n == 1 else "0")
