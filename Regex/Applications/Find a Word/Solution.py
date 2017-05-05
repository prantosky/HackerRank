import re

n = int(input())
string = '\n'.join([input() for i in range(n)])
q = int(input())
for i in range(q):
    Regex_Pattern = r'(\W|\b)' + input() + r'(\b|\W)'
    print(len(re.findall(Regex_Pattern, string)))
