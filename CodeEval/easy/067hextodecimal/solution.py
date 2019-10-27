#!/usr/bin/env python

from sys import argv
for line in open(argv[1], 'r'):
    print(int(line, 16))
