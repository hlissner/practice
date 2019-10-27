#!/usr/bin/env python

from sys import argv
for line in open(argv[1]):
    x, y = line.split(",")
    print(int(x) % int(y))
