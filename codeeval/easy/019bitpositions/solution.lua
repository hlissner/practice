#!/usr/bin/env lua

for line in io.lines(arg[1]) do
  n = {}
  for str in line:gmatch("([^,]+)") do
    table.insert(n, tonumber(str))
  end

  if bit32.band(bit32.rshift(n[1], n[2]-1), 1) == bit32.band(bit32.rshift(n[1], n[3]-1), 1) then
    print("true")
  else
    print("false")
  end
end
