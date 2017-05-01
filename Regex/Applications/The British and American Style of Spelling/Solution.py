#!bin/python3

import re

n = int(input())
string = '\n'.join(input() for i in range(n))
t = int(input())
for i in range(t):
    word = input()
    word = word[0:len(word) - 2] + '[zs]e'
    print(len(re.findall(word,string)))
