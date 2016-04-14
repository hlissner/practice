#!/usr/bin/env lua
-- 007: 10,001st prime - Lua
-- https://projecteuler.net/problem=7
--
-- By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see that the 6th
-- prime is 13.
--
-- What is the 10 001st prime number?

-- NOTE: let n ∈ P, where P is the set of primes
-- + 1 ∉ P
-- + ∀p ∈ P, p >= 3: n is odd
-- + ∀p ∈ P, p = 6k±1
-- + n ∈ P if n ∤ 6k±1 where 3 <= k < sqrt(n)

function isPrime(n)
  if n == 1 then
    return false
  elseif n <= 3 then
    return true
  elseif (n % 2) == 0 or (n % 3) == 0 then
    return false
  elseif n < 9 then
    return true
  else
    for i=6, math.sqrt(n)+1, 6 do
      if (n % (i-1)) == 0 or (n % (i+1)) == 0 then
        return false
      end
    end

    return true
  end
end

function nthPrime(i)
  j = 2
  n = 3
  while j < i do
    n = n + 2

    if isPrime(n) then
      j = j + 1
    end
  end
  return n
end

print(nthPrime(10001))
