#!/usr/bin/env ruby

File.foreach(ARGV.first) do |line|
  line = line.strip()
  if line.size <= 55
    puts line
  else
    line = line[0,40]
    lsi = line.rindex(" ")
    line = line[0,lsi] if lsi
    puts "#{line}... <Read More>"
  end
end
