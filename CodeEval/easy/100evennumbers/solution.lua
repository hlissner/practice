#!/usr/bin/env lua

for line in io.lines(arg[1]) do
  if bit32.band(tonumber(line), 1) == 0 then
    print(1)
  else
    print(0)
  end
end
