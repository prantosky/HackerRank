#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main(){
	int test,*alpha,len,temp,count=0,temp1;
	char str[101];
	register int i,j;
	alpha=(int*)calloc(26,sizeof(int));
	if(alpha==NULL) {
		return -1;
	}
	scanf("%d",&test); 
	temp=test;
	while(test--){
		scanf("%s",str);
		len=strlen(str);
		for(i=0;i<len;i++){
			if(str[i]=='0'){
				continue;
			}
			for(j=i+1;j<len;j++){
				if(str[i]=='0'){
					continue; 
				}
				if(str[i]==str[j]){
					str[j]='0';
				}
			}
		}
		for(i=0;i<len;i++){
			if(str[i]=='0')
			{
				continue;
			}
			temp1=str[i]-97;
			alpha[temp1]++;
		}
	}
	for(i=0;i<26;i++){
		if(alpha[i]==temp) {
			count++;
		}
	}
	printf("%d\n",count); 
	free(alpha);
	return 0;
}