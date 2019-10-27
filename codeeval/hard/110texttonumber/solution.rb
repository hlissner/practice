#!/usr/bin/env ruby

PREFIXES = {
  'twelve'  => 12,
  'eleven'  => 11,
  'ten'     => 10,
  'nine'    => 9,
  'eigh'    => 8,
  'eight'   => 8,
  'seven'   => 7,
  'six'     => 6,
  'five'    => 5,
  'fif'     => 5,
  'four'    => 4,
  'for'     => 4,
  'three'   => 3,
  'thir'    => 3,
  'two'     => 2,
  'twen'    => 2,
  'one'     => 1
}

MODIFIERS = {
  "million"  => 1000000,
  "thousand" => 1000,
  "hundred"  => 100
}

SUFFIXES = {
  'teen' => lambda { |n| n + 10 },
  'ty'   => lambda { |n| n * 10 }
}

def sub_to_number(words)
  n = 0
  local = 0
  words.each do |word|
    if word =~ /^(#{PREFIXES.keys.join("|")})/
      local = PREFIXES[$1]
      if word =~ /#{$1}(#{SUFFIXES.keys.join("|")})$/
        local = SUFFIXES[$1].call(local)
      end
      n += local
    end
  end

  return n
end

def to_number(words)
  words = words.split(" ") unless words.instance_of? Array
  return 0 if words == ["zero"]

  mult = 1
  mult = -1 and words.shift if words.first == "negative"

  n = 0
  mods = (MODIFIERS.keys & words)
  if mods.any?
    mods.each do |modifier|
      i = words.rindex(modifier)
      if i
        a = words.slice!(0, i+1)
        a.pop
        n += (to_number(a) * MODIFIERS[modifier]) + to_number(words)
      end
    end
  else
    n += sub_to_number(words)
  end

  return n * mult
end

File.open(ARGV[0]).each_line do |line|
  next if line.strip.empty?
  puts to_number(line.strip)
end

