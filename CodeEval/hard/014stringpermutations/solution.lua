#!/usr/bin/env lua

-- 2ms 118.303kb 99.708

function permutations(word)
  if #word == 1 then
    return {word}
  end

  local first_letter = word:sub(1, 1)
  local perms = permutations(word:sub(2, #word))
  result = {}
  for i = 1,#perms do
    local perm = perms[i]
    for j = 1,(#perm+1) do
      table.insert(result, perm:sub(1, j-1) .. first_letter .. perm:sub(j, #perm))
    end
  end
  return result
end

for line in io.lines(arg[1]) do
  local p = permutations(line)
  table.sort(p)
  print(table.concat(p, ","))
end
