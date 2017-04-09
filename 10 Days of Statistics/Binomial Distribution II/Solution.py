from functools import reduce
import operator as op
def nCr(n,r):
    if(r==0 or n==0 or n==1):
        return 1
    numerator=reduce(op.mul,range(n,n-r,-1))
    denominator=reduce(op.mul,range(1,r+1))
    return numerator//denominator

p=0.12
q=1-p
ans=0
for i in range(0,3):
    ans+=nCr(10,i)*pow(p,i)*pow(q,10-i)
print(round(ans,3))
ans=0
for i in range(2,11):
    ans+=nCr(10,i)*pow(p,i)*pow(q,10-i)
print(round(ans,3))