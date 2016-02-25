#!/usr/bin/env ruby

def permutations(word)
  return [word] if word.length == 1
  perms = permutations(word[1..-1])
  result = []
  perms.each do |perm|
    (perm.length+1).times do |i|
      result.push("#{perm[0...i]}#{word[0]}#{perm[i..-1]}")
    end
  end
  return result
end

File.open(ARGV[0]).each_line do |line|
  line.strip!
  next if line.empty?
  puts permutations(line).sort.join(",")
end
