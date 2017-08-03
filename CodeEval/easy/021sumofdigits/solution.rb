#!/usr/bin/env ruby

File.open(ARGV[0]).each_line do |line|
  next if line.strip.empty?
  puts line.split("").reduce { |sum, n| sum.to_i + n.to_i }
end
