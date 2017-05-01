#!bin/python3
import re

n = int(input())
string = '\n'.join([input() for i in range(n)])
q = int(input())
for i in range(q):
    query = input()
    Regex_Pattern = r'(?<=\w)' + query + r'(?=\w)'
    print(len(re.findall(Regex_Pattern, string)))
