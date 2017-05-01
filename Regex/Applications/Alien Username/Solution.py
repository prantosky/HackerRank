#!bin/python3

import re

n = int(input())
Regex_Pattern=r'^[._][0-9]+[a-zA-Z]*_?$'
pattern=re.compile(Regex_Pattern)
for i in range(n):
    if pattern.match(input()):
        print('VALID')
    else:
        print('INVALID')