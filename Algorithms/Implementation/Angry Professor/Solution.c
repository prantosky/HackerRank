#include<stdio.h>
int main()
{
	int test, n,k,temp, count=0;
	register int i; 
	scanf("%d",&test) ;
	while(test--){
		scanf("%d%d",&n, &k) ;
		for(i=0;i<n;i++){
			scanf("%d",&temp);
			if(temp<=0){
				count++;
			}
		}
		if(count<k){
			puts("YES") ;
		}
		else{
			puts("NO");
		}
       count =0;
	}
	return 0;
}