#!/usr/bin/env ruby

File.foreach(ARGV[0]).each do |line|
  puts line.to_i(16)
end
