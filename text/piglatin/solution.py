#!/usr/bin/env python

import sys

def pig_latinify(text):
    words = text.split()
    for i in range(len(words)):
        append = ""
        if words[i][-1] in ",.!?":
            append = words[i][-1]
            word = words[i][0:-1]
        else:
            word = words[i]
        if word[0] in "aeiou":
            words[i] += "way"
        # Take consonant clusters into account
        elif word[0:2].lower() in ['bl', 'br', 'ch', 'cl', 'fl', 'fr', 'gl', 'gr', 'ph', 'pl', 'sh', 'sl', 'st', 'tr']:
            words[i] = word[2:] + word[0:2].lower() + "ay"
        else:
            words[i] = word[1:] + word[0].lower() + "ay"
        words[i] += append
    return " ".join(words)

if len(sys.argv) > 1:
    print(pig_latinify(sys.argv[1]))
else:
    print("Usage {0} [sentence]".format(sys.argv[0]))
