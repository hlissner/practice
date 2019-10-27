#!/usr/bin/env ruby

def isprime(n)
  return false if n&1 == 0
  (3..Math.sqrt(n)).step(2) do |i|
    return false if n % i == 0
  end
  true
end

def primes(n)
  i = 1
  sum = 2
  x = 3
  until i >= n
    sum += x
    x += 2
    x += 2 until isprime(x)
    i += 1
  end
  sum
end

puts primes(1000)
