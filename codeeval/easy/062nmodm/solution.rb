#!/usr/bin/env ruby

File.open(ARGV[0]).each_line do |line|
  x,y = line.split(",")
  puts x.to_i % y.to_i
end
