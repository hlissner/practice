#!/usr/bin/env python

from sys import argv

with open(argv[1]) as f:
    n = int(f.readline())
    lines = [line.strip() for line in f]
    lines.sort(key=len, reverse=True)
    print("\n".join(lines[0:n]))
