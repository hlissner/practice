#!/usr/bin/env lua

for l in io.lines(arg[1]) do
  txt, char = l:match("([^,]+),([^,]+)")
  print((txt:find(char .. "[^" .. char .. "]*$") or 0) - 1)
end
