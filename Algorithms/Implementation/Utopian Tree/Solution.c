#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
int main(){
	int n,*ptr,*ans,flag,temp;
	register int i;
	scanf("%d",&n);
	ptr=(int*) calloc(n,sizeof(int));
	ans=(int*) calloc(n,sizeof(int));
	if(ptr==NULL||ans==NULL){
		puts("Memory Allocation Failed");
		return -1;
	}
	for(i=0;i<n;i++,ans++,ptr++){
		scanf("%d",ptr);
		*ans=1;
	}
	for(i=0;i<n;i++){
		ptr--;
		ans--;
		flag=0;
		for(temp=(*ptr);temp>0;temp--){
			if(flag==0){
				*ans=2*(*ans);
				flag=1;
			}else if(flag==1){
				*ans+=1;
				flag=0;
			}
		}
	}
	for(i=0;i<n;i++){
		printf("%d\n",*ans);
		ans++;
	}
	return 0;
}