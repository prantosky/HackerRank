import re

n = int(input())
regex = r'^[A-Z]{5}\d{4}[A-Z]$'
pattern = re.compile(regex)
for i in range(n):
    if pattern.match(input()):
        print('YES')
    else:
        print('NO')
