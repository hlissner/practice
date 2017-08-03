#!/usr/bin/env python

from sys import argv

for line in open(argv[1]):
    src, sub = line.split(", ")
    for l in sub:
        src = src.replace(l, "")
    print(src)
