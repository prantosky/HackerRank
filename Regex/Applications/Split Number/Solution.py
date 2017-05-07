import re

regex = r'(\d{1,3})(-| )(\d{1,3})(-| )(\d{4,10})'
pattern = re.compile(regex)
n = int(input())
for i in range(n):
    m = pattern.match(input())
    if m:
        print('CountryCode='+m.group(1), 'LocalAreaCode='+m.group(3), 'Number='+m.group(5), sep=',')
