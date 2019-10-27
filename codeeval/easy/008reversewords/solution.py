from sys import argv

for line in open(argv[1]):
    words = line.strip().split(" ")
    words.reverse()
    print(" ".join(words))
