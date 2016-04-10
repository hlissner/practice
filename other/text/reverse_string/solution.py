#!/usr/bin/env python

import sys
import unicodedata

if sys.version_info[0] < 3:
    # PYTHON 2.7.8 SOLUTION

    text = unicode(raw_input(), 'utf')

    # unicode() is enough for anything between UCS-2 and single-code-unit UTF-16
    # characters, but some shenanigans are in order so that double-code-unit
    # UTF-16 characters (i.e. surrogate pairs) behave, otherwise the reversal
    # will reverse each individual code unit, rather than the whole UTF-8 code
    # point.
    newstr = ""
    batch = []
    for i in range(len(text)-1, -1, -1):
        uname = unicodedata.name(text[i], '')
        if 'COMBINING' in uname or uname == "":
            batch.insert(0, text[i])
        else:
            if len(batch) > 0:
                newstr += "".join(batch)
                batch = []
            newstr += text[i]

    print(newstr)
else:
    # PYTHON 3.4.1 SOLUTION

    # raw_input is now input in python 3, and unicode support is built right in
    # (even handles surrogate pairs! Glorious!)
    print(input()[::-1])
    # Easy!
