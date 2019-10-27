#!/usr/bin/env python

from sys import argv

DENOM = [5, 3, 1]

for x in open(argv[1]):
    amt = int(x)
    coins = 0
    for d in DENOM:
        qty = int(amt / d)
        amt -= qty * d
        coins += qty
    print(coins)
