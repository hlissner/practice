#!/usr/bin/env python

from sys import argv
print(sum([int(x) for x in open(argv[1])]))
