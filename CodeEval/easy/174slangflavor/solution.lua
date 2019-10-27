#!/usr/bin/env lua

SLANG = {
  ", yeah!",
  ", this is crazy, I tell ya.",
  ", can U believe this?",
  ", eh?",
  ", aw yea.",
  ", yo.",
  "? No way!",
  ". Awesome!"
}

slang_id = 0
other = false
for line in io.lines(arg[1]) do
  for c in line:gmatch"." do
    if c == '.' or c == '?' or c == '!' then
      if other then
        io.write(SLANG[math.fmod(slang_id, 8) + 1])
        slang_id = slang_id + 1
      else
        io.write(c)
      end
      other = not other
    else
      io.write(c)
    end
  end
  io.write("\n")
end
