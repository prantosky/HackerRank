import re
from os import sys

input = sys.stdin.read()
pattern = r'<\s*(\w+)((\s\w+=.*?)*)\s*/?>'
attributes = dict()
for i in re.findall(pattern, input):
    attributes.setdefault(i[0], set())
    for j in re.sub('".*?"', '', i[1].strip()).split(' '):
        attributes[i[0]].add(j.split('=')[0])

for tag in sorted(attributes.keys()):
    print(tag, ','.join(sorted(attributes[tag])), sep=':')
