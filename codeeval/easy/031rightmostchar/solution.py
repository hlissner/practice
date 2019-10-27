#!/usr/bin/env python

from sys import argv

for line in open(argv[1]):
    src, sub = line.strip().split(",")
    try:
        if sub == "":
            raise ValueError
        print(src.rindex(sub))
    except:
        print(-1)
