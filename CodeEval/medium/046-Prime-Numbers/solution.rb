#!/usr/bin/env ruby

def isprime(n)
  return false if n % 2 == 0
  (3..Math.sqrt(n).to_i).step(2) { |i| return false if n % i == 0 }
  return true
end

def primes(n)
  (3...n).step(2) { |i| yield i if isprime(i) }
end

File.open(ARGV[0]).each_line do |line|
  n = line.to_i
  if n > 2
    print 2
    primes(n) { |i| print ",", i }
  end
  puts
end
