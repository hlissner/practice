#!/usr/bin/env ruby

File.open(ARGV[0]).each_line do |line|
  next if line.strip.empty?

  x, y, max = line.split(" ").map { |n| n.to_i }
  puts (1..max).map { |n|
    out = "#{"F" if n % x == 0}#{"B" if n % y == 0}"
    "#{out.empty? ? n : out}"
  }.join(" ")
end
