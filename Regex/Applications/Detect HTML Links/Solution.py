import re

n = int(input())
string = ''
for i in range(n):
    string += input()
Regex_Pattern = r'<a\shref="(.*?)".*?>(.*?)</a>'
matches = re.finditer(Regex_Pattern, string)
for match in matches:
    print(match.group(1),re.sub(r'<.*?>','',match.group(2)).strip(),sep=',')
