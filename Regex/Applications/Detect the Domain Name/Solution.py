import re
from os import sys

input = sys.stdin.read()
pattern = r'https?://(ww.\.)?(.*?)[\' \\/?"_]'
urls = set()
for i in re.findall(pattern, input):
    if len(i[1].split('.')) > 1:
        urls.add(i[1])
        # print(i[1])
print(';'.join(sorted(urls)))
# print(sorted(urls))
