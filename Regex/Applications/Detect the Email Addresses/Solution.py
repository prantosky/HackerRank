import re

n = int(input())
string = '\n'.join([input() for i in range(n)])
Regex_Pattern = r'\b\S+@\S+\.\w+'
lst = re.findall(Regex_Pattern, string)
lst = list(set(lst))
lst.sort()
print(';'.join(lst))