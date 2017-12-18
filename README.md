# Rabin-Karp Algorithm Implementation
This program implements the Rabin-Karp string matching algorithm with custom hash function

## How it works...
Let's understand how it works.
Suppose, we have two strings s1 and s2, and we need two find all occurences of s2 in s1 and print these occurences indexes.
With this algorithm, we need to calculate hash of the s2 at first, after we need to calculate hash of the first s2.length() substring of s1, and compare them, if they're equal, compare s1 and that substring, if they're equal too that means that we've found the occurence. We need to repeat these steps until the end of S1.
This algorithm will give to us linear big-O complexity.
