#!/usr/bin/env python

from sys import argv
for test in open(argv[1], "r"):
    if test.strip() == "":
        continue
    x, y, max = test.split(" ")
    for i in range(1, int(max) + 1):
        out = ""
        if i % int(x) == 0:
            out += "F"
        if i % int(y) == 0:
            out += "B"
        print(out or i, end=" ")
    print()
