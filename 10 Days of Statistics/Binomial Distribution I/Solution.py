from functools import reduce
import operator as op
def nCr(n,r):
    numerator=reduce(op.mul,range(n,n-r,-1))
    denominator=reduce(op.mul,range(1,r+1))
    return numerator//denominator

p=1.09/(1+1.09)
q=1/(1+1.09)
ans=0
for i in range(3,7):
    ans+=nCr(6,i)*pow(p,i)*pow(q,6-i)
print(round(ans,3))