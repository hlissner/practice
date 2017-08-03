#!/usr/bin/env python

from sys import argv

def permutations(word):
    if len(word) == 1:
        return [word]
    first = word[0]
    perms = permutations(word[1:])
    result = []
    for perm in perms:
        for i in range(len(perm)+1):
            result.append(perm[:i] + first + perm[i:])
    return result

for line in open(argv[1], 'r'):
    line = line.strip()
    if line == "":
        continue
    print(",".join(sorted(permutations(line))))
