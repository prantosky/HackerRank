import re

n = int(input())
regex = r'hackerrank'
pattern = re.compile(regex)
for i in range(n):
    string = input()
    m = pattern.search(string)
    if m:
        pos = m.span()
        if pos[0] == 0 and pos[1] == len(string):
            print('0')
        elif pos[0] == 0:
            print('1')
        elif pos[1] == len(string):
            print('2')
        else:
            print('-1')
