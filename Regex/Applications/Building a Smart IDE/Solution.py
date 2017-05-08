import re
from sys import stdin

regex = r'(/\*.*?\*/|//.*?$)'
string = ''.join(stdin.readlines())
string=re.sub(r'\n\s+', r'\n',string)
lst = re.findall(regex, string, re.DOTALL | re.MULTILINE)
for i in lst:
    print(i)
