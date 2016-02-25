#!/usr/bin/env ruby

# A little cheat-ey, but I solved this in C++ already. Here I'm just experimenting with
# the language.

File.open(ARGV[0]).each_line do |line|
  str, query = line.strip.split(",")
  puts str =~ /#{query.gsub(/(?<!\\)\*/, ".*")}/ ? "true" : "false"
end
