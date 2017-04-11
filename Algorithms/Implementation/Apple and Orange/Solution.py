#!/bin/python3

s,t = input().strip().split(' ')
s,t = [int(s),int(t)]
a,b = input().strip().split(' ')
a,b = [int(a),int(b)]
m,n = input().strip().split(' ')
m,n = [int(m),int(n)]

apple = [int(apple_temp) for apple_temp in input().strip().split(' ')]
orange = [int(orange_temp) for orange_temp in input().strip().split(' ')]

fallen_apples=0
fallen_oranges=0

for d in apple:
    if d >= s-a and d<= t-a:
        fallen_apples+=1
for d in orange:
    if d <= t-b and d >= s-b:
        fallen_oranges+=1
print(fallen_apples)
print(fallen_oranges)