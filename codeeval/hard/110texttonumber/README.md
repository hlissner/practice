# 110: Text to Number

> Source: https://www.codeeval.com/open_challenges/110/

You have a sting which contains a number represented as English text. Your task is to
translate these numbers into their integer representation. The numbers can range from
negative 999,999,999 to positive 999,999,999. The following is an exhaustive list of
English words that your program must account for:

+ Negative numbers will be preceded by the word negative.
+ The word "hundred" is not used when "thousand" could be. e.g. 1500 is written "one
  thousand five hundred", not "fifteen hundred".

```
negative,
zero, one, two, three, four, five, six, seven, eight, nine,
ten, eleven, twelve, thirteen, fourteen, fifteen, sixteen, seventeen, eighteen, nineteen,
twenty, thirty, forty, fifty, sixty, seventy, eighty, ninety,
hundred,
thousand,
million
```

## Input sample

Your program should accept as its first argument a path to a filename. Input example is
the following:

```
fifteen
negative six hundred thirty eight
zero
two million one hundred seven
```

- Negative numbers will be preceded by the word negative.
- The word "hundred" is not used when "thousand" could be. E.g. 1500 is written "one
  thousand five hundred", not "fifteen hundred".

## Output sample

Print results in the following way.

```
15
-638
0
2000107
```

