#!/usr/bin/env lua

for line in io.lines(arg[1]) do
  n, m = line:match("([^,]+),([^,]+)")
  io.write(n - math.floor(n/m)*m .. '\n')
end
