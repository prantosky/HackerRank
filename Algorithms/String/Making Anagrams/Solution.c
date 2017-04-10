#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
	int *alpha1,*alpha2,len1,len2,count=0;
	char str[10001];
	register int i;
	alpha1=(int*)calloc(26,sizeof(int));
	alpha2=(int*)calloc(26,sizeof(int));
	if(alpha1==NULL || alpha2==NULL) {
		return -1;
	}
	scanf("%s",str);
	len1=strlen(str);
	for(i=0;i<len1;i++){
		alpha1[str[i]-97]++;
	}
	scanf("%s",str); 
	len2=strlen(str);
	for(i=0;i<len2;i++){
		alpha2[str[i]-97]++;
	}
	for(i=0;i<26;i++){
		count=count+abs(alpha1[i]-alpha2[i]);
	}
	printf("%d\n",count); 
	return 0;
}