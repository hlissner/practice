#!/usr/bin/env python

from sys import argv
with open(argv[1], 'r') as f:
    print(f.read().lower())
