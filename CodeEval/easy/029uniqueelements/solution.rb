#!/usr/bin/env ruby

File.open(ARGV[0]).each_line do |line|
  puts line.split(",").map { |x| x.to_i }.uniq.sort.join(",")
end
