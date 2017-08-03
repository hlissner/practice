#!/usr/bin/env python

from sys import argv

bool = {True: 'true', False: 'false'}

for line in open(argv[1], 'r'):
    n, i, j = map(int, line.strip().split(","))
    print(bool[(n >> i - 1) & 1 == (n >> j - 1) & 1])
