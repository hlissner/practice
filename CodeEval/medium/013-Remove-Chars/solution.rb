File.open(ARGV[0]).each_line do |line|
  text, rep = line.split(", ")
  puts text.gsub(/[#{Regexp.escape(rep)}]/, "")
end
