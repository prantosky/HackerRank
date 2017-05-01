#!bin/python3
import re

n = int(input())
string = ''
for i in range(n):
    string += input()

Regex_Pattern = r'<(\w+).*?/?>'
lst = re.findall(Regex_Pattern, string)
lst = list(set(lst))
lst.sort()
for i in range(len(lst)):
    print(lst[i], end='')
    if not i == len(lst) - 1:
        print(';', end='')