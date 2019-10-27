#!/usr/bin/env lua

for line in io.lines(arg[1]) do
  arrows = 0
  for i = 1,#line do
    local c = line:sub(i,i)
    if (c == "<" and line:sub(i,i+4) == "<--<<") or
       (c == ">" and line:sub(i,i+4) == ">>-->") then
      arrows = arrows + 1
    end
  end
  print(arrows)
end
