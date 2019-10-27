#!/usr/bin/env ruby

ARGV[0] = "/Users/hlissner/Desktop/data"

File.open(ARGV[0]).each_line do |line|
  puts line.split(" ")[-2]
end
