#!bin/python3

import re

n = int(input())
string = '\n'.join(input() for i in range(n))
t = int(input())
for i in range(t):
    word = input()
    lst = word.split('our')
    word = r'\b'+lst[0] + 'ou?r' + lst[1]+r'\b'
    print(len(re.findall(word, string)))
