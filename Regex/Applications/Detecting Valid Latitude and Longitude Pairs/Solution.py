import re


def isValid(string):
    if pattern.match(string):
        return 'Valid'
    else:
        return 'Invalid'


pattern = re.compile(r'[(][-+]?(([0-8]?\d(\.\d+)?)|(90(\.0+)?)), [-+]?(((\d|1[0-7])\d(\.\d+)?)|(180(\.0+)?))[)]$')
n = int(input())
for i in range(n):
    print(isValid(input()))
