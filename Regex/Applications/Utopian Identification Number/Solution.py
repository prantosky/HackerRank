import re

n = int(input())
regex = r'^[a-z]{0,3}\d{2,8}[A-Z]{3}[A-Z]*$'
pattern = re.compile(regex)
for i in range(n):
    if pattern.match(input()):
        print('VALID')
    else:
        print('INVALID')
