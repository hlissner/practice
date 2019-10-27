File.open(ARGV[0]).each_line do |line| 
  x, n = line.strip.split(",").map { |n| n.to_i }
  i = n
  i += n until i >= x
  puts i
end
