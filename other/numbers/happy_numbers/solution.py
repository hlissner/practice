#!/usr/bin/env python

import sys

# How to use:
#   python solution.py 10 11 12
#       Checks if 10, 11 and 12 are happy numbers
#   python solution.py 10-12 15 19-30
#       Checks if 10-12, 15 and 19-30 are happy numbers
#   python solution.py
#       Get's first 8 happy numbers

def happy_proc(n):
    sum = 0

    # I exploit the properties of strings because I extra digits w/ modulus in the
    # C++ solution.
    for i in str(n):
        sum += int(i)**2
    return sum

def happy_check(n, max_tries=100):
    for i in range(max_tries):
        n = happy_proc(n)
        if n == 1: return True
    return False

def is_happy(n):
    print(n, "Happy!" if happy_check(n) else "Unhappy.")

if len(sys.argv) > 1:
    for num in sys.argv[1:]:
        if num.find("-") == -1:
            is_happy(int(num))
        else:
            nums = num.split('-')
            for i in range(int(nums[0]), int(nums[1])+1):
                is_happy(i)
else:
    print("Printing first 8 happy numbers")
    n = 1
    happy = 0
    while happy <= 8:
        if happy_check(n):
            print(n)
            happy += 1
        n += 1
