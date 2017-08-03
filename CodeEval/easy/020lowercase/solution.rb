#!/usr/bin/env ruby

File.open(ARGV[0]).each_line do |line|
  next if line.strip.empty?
  puts line.downcase
end
