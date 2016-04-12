-- 007: 10,001st prime - Lua
-- https://projecteuler.net/problem=7
--
-- By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see that the 6th
-- prime is 13.
--
-- What is the 10 001st prime number?

-- NOTE: Would be faster if I used a prime sieve
function isPrime(n)
  if n <= 3 then return true end
  if ((n % 2) == 0) or (n % 5 == 0) then
    return false
  end

  for i=3, math.sqrt(n), 2 do
    if n % i == 0 then
      return false
    end
  end

  return true
end

function nthPrime(i)
  i = i - 1

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
