#!/usr/bin/env lua

for line in io.lines(arg[1]) do
  print(tonumber(line, 16))
end
