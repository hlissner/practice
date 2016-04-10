#!/usr/bin/env python

# Since this problem is so simple, I'm only doing a python solution

for num in range(1, 101):
    words = ""
    if num % 3 == 0:
        words += "Fizz"
    if num % 5 == 0:
        words += "Buzz"
    print(words or num)
