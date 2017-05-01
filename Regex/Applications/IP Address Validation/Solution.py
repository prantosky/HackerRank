#!bin/python3

import re

regex_ipv4 = re.compile(r'^(([01]?\d{1,2}|2[0-5]{2})\.){3}([01]?\d{1,2}|2[0-5]{2})$')
regex_ipv6 = re.compile(r'^([\da-f]{1,4}:){7}[\da-f]{1,4}$')

n = int(input())
for i in range(n):
    string = input()
    if regex_ipv4.match(string):
        print('IPv4')
    elif regex_ipv6.match(string):
        print('IPv6')
    else:
        print('Neither')