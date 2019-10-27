#!/usr/bin/env python

from sys import argv

argv = [None, "/Users/hlissner/Desktop/data"]

for line in open(argv[1]):
    line = line.strip()
    if len(line) > 55:
        line = line[0:40]
        lsi = line.rfind(" ")
        if lsi != -1:
            line = line[0:lsi+1]
        line = line.strip()
        line += "... <Read More>"
    print(line)
