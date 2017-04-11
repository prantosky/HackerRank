#!/bin/python3

def natural_num():
    i=1
    while True:
        yield i
        i+=1

x1,v1,x2,v2 = input().strip().split(' ')
x1,v1,x2,v2 = [int(x1),int(v1),int(x2),int(v2)]

if v2 >= v1 :
    print("NO")
else:
    flag=False
    n = natural_num()
    i=next(n)
    while(x1+i*v1<=x2+i*v2):
        if(x1+i*v1==x2+i*v2):
            flag=True
            break
        i=next(n)
if(flag):
    print("YES")
else:
    print("NO")