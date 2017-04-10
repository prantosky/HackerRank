#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void reset(int*,int*);
int main(){
	int *alpha1,*alpha2, count=0,len,test;
	char str[10001];
	register int i; 
	alpha1=(int*)calloc(26,sizeof(int));
	alpha2=(int*)calloc(26,sizeof(int));
	if(alpha1==NULL || alpha2==NULL) {
		return -1;
	}
	scanf("%d",&test); 
	while(test--){
		scanf("%s" ,str);
		len=strlen(str);
		if(len%2){
			puts("-1");
			continue; 
		}
		for(i=0;i<len/2;i++){
			alpha1[str[i]-97]++;
			alpha2[str[len/2+i]-97]++;
		}
		for(i=0;i<26;i++){
			count+=abs(alpha1[i]-alpha2[i]);
		}
		printf("%d\n",count/2);
		count=0;
		reset(alpha1,alpha2);
	}
    free(alpha1);
    free(alpha2);
	return 0;
}
void reset(int *alpha1,int *alpha) {
	register int i; 
	for(i=0;i<26;i++){
		alpha1[i]=alpha[i]=0;
	}
}