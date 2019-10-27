#!/usr/bin/env ruby

def happy_proc(n)
  n.to_s.split("").reduce(0) { |sum, x| sum + x.to_i**2 }
end

File.open(ARGV[0]).each_line do |line|
  max = 30
  n = line.to_i
  until n == 1 or max <= 0
    n = happy_proc(n)
    max -= 1
  end
  puts n == 1 ? "1" : "0"
end
