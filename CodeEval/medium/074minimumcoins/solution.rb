#!/usr/bin/env ruby

denom = [5, 3, 1]

File.open(ARGV[0]).each_line do |line|
  amt = line.to_i
  coins = 0
  denom.each do |n|
    qty = (amt / n).to_i
    amt -= qty * n
    coins += qty
  end
  puts coins
end
