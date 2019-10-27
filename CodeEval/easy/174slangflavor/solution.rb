#!/usr/bin/env ruby

ARGV[0] = "/Users/hlissner/tmp/data"

slang = [
  ', yeah!',
  ', this is crazy, I tell ya.',
  ', can U believe this?',
  ', eh?',
  ', aw yea.',
  ', yo.',
  '? No way!',
  '. Awesome!'
]

i = 0
n = -1
ss = slang.size
puts File.read(ARGV.first).gsub(/[.!?]/) { |match|
  n += 1
  if (n&1).zero?
    match
  else
    i += 1
    slang[(i-1) % ss]
  end
}.to_s
