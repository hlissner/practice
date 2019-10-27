#!/usr/bin/env python

import re
from sys import argv

# Regular expressions are a poor way of validating emails. These patterns were designed
# solely for this problem and should never be used in production.

with open(argv[1], 'r') as f:
    for line in f:
        line = line.strip()
        if line:
            if re.match('^(' +
                        '\w[\w.+-]*' +
                        '|((^|\.)"\w[\w@.+ -]+")+' +
                        ')@\w[\w+.]*\.(com|org|net)$',
                        line):
                print("true")
            else:
                print("false")
