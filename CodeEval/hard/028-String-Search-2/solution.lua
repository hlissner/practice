#!/usr/bin/env lua

-- A little cheat-ey, but the C++ one is the real solution. Check that one out. Here I'm
-- leveraging Lua's own pattern system (it doesn't have a regex library; one would
-- likely be larger than lua itself).

for line in io.lines(arg[1]) do
  data = {}
  for str in line:gmatch("([^,]+)") do
    table.insert(data, str)
  end
  pat = data[2]:gsub("[^\\]([*-?+%.[$()])", ".%1")
  if pat:sub(1,1) == "*" then
    pat = "." .. pat
  end
  print(not not data[1]:find(pat))
end

