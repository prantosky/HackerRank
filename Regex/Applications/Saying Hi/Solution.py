import re

n = int(input())
regex = r'^hi\s(?!d)'
pattern = re.compile(regex,re.IGNORECASE)
for i in range(n):
    string = input()
    if pattern.match(string):
        print(string)
