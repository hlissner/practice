#!/usr/bin/env ruby

File.foreach(ARGV[0]).each do |line|
  n,i,j = line.strip.split(",").map { |x| x.to_i }
  a = (n >> i-1) & 1
  b = (n >> j-1) & 1
  puts a == b ? "true" : "false"
end
