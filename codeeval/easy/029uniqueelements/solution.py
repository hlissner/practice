#!/usr/bin/env python

from sys import argv

for line in open(argv[1]):
    l = list(map(int, set(line.strip().split(","))))
    l.sort()
    print(",".join(map(str, l)))
