#include <stdio.h>

int memalloc(int,int);
int fillarray(int,int,int);


int main(){
	int temp1;
	int l,r,i,memsize;
	scanf("%d%d",&l,&r);
	memsize=memalloc(l,r);
	printf("%d",fillarray(memsize,l,r));
	return 0;
}


int memalloc(int a,int b){
	int c,ret;
	for(c=b-a+1,ret=0;c>0;c--)
		ret+=c;
	return ret;
}


int fillarray(int size,int l,int r){
	int temp,i,ans=0,tempans;
	temp=r;
	r=l;
	for(i=0;i<size;i++){
		tempans=l^r;
		if(ans<tempans)
			ans=tempans;
		r++;
		if(r>temp){
			l++;
			r=l;
		}
	}
	return ans;
}