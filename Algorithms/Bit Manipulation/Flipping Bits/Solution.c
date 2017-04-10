#include <stdio.h>
#include <math.h>

int main(){
	unsigned int a[32],n,b,i,n1;
	int c,j;
	scanf("%d",&c);
	for(i=0;i<=32;i++){
		a[i]=0;
	}
	for(j=0;j<c;j++){
		scanf("%u",&n);
		for(i=0;i<=32;i++){
			b=n%2;
			a[32-i]=b;
			n=n/2;
		}
		for(i=0;i<=32;i++) {
			if(a[i]==0){
				a[i]=1;
			}else{
				a[i]=0;
			}
		} 
		for(i=0;i<=32;i++){
			if(a[i]==1){
				n1=n1+pow(2,32-i);
			}
		}
		printf("%u\n",n1);
		for(i=0;i<=32;i++){
			a[i]=0;
		}
		b=0;n1=0;
	}
	return 0;
} 