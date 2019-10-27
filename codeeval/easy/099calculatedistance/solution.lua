#!/usr/bin/env lua

for line in io.lines(arg[1]) do
  ax, ay, bx, by = line:match("%(([^,]+), ([^,]+)%) %(([^,]+), ([^,]+)%)")

  x = tonumber(bx) - tonumber(ax)
  y = tonumber(by) - tonumber(ay)
  io.write(math.sqrt(x*x + y*y) .. '\n')
end
