#!/usr/bin/env ruby

File.open(ARGV.first).each_line do |line|
  src, sub = line.strip.split(",")
  if sub
    pos = src.rindex(sub)
    puts pos.nil? ? -1 : pos
  else
    puts -1
  end
end
