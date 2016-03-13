# 013: Remove Characters

> Source: https://www.codeeval.com/open_challenges/013/

Write a program which removes specific characters from a string.

The first argument is a path to a file. The file contains the source strings and the
characters that need to be scrubbed. Each source string and characters you need to scrub
are delimited by comma.

## Input sample

The first argument is a path to a file. The file contains the source strings and the
characters that need to be scrubbed. Each source string and characters you need to scrub
are delimited by comma.

```
how are you, abc
hello world, def
```

## Output sample

Print to stdout the scrubbed strings, one per line. Ensure that there are no trailing
empty spaces on each line you print.

```
how re you
hllo worl
```
