#!/usr/bin/env python

from sys import argv, stdout

SLANG = [
    ", yeah!",
    ", this is crazy, I tell ya.",
    ", can U believe this?",
    ", eh?",
    ", aw yea.",
    ", yo.",
    "? No way!",
    ". Awesome!"
]

slang_id = 0
other = False
for line in open(argv[1], "r"):
    for c in line:
        if c in '.?!':
            if other:
                stdout.write(SLANG[slang_id % 8])
                slang_id += 1
            else:
                stdout.write(c)
            other = not other
        else:
            stdout.write(c)

