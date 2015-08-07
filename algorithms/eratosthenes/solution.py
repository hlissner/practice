#!/usr/bin/env python

def eratosthenes(max):
    nums = [False, False] + ([True] * (max - 2))
    for (i, prime) in enumerate(nums):
        if prime:
            yield i
            for n in range(i * i, max, i):  # use xrange in python 2
                nums[n] = False


if __name__ == '__main__':
    for i in eratosthenes(int(10e6)):
        print(i)
