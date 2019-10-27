#!/usr/bin/env lua

-- Yet another situation where regex saves the day when it comes to unicode!

input = io.stdin:read("*l")
input = input:gsub('[%z\1-\127\194-\244][\128-\191]*', function (c) return #c > 1 and c:reverse() end)
print(input:reverse())
