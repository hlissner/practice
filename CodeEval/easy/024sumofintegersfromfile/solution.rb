#!/usr/bin/env ruby

puts File.open(ARGV.first).each_line.reduce(0) { |sum, x| sum += x.to_i }
