-- 004: Largest palindrom product - Haskell
-- https://projecteuler.net/problem=4
--
-- A palindromic number reads the same both ways. The largest palindrome made from the
-- product of two 2-digit numbers is 9009 = 91 x 99.
--
-- Find the largest palindrome made from the product of two 3-digit numbers.

largestPalindrome =
  maximum [n | x <- [100..999], y <- [100..999],
           let n = x*y, let str = show n, str == reverse str]
