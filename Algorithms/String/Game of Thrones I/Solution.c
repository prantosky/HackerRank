#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define size 100001
int main(){
	char str[size];
	int *alph,len=0,flag=0;
	register int i;
	alph=(int*)calloc(26,sizeof(int));
	scanf("%s",str);
	len=strlen(str);
	for(i=0;i<len;i++)
		alph[str[i]-97]++;
	if(len%2!=0){
		for(i=0;i<26;i++){
			if(alph[i]%2==0){
				continue;
			}
			else if(alph[i]%2!=0 && flag==0){
				flag=1;
				continue;
			}
			else if(alph[i]%2!=0 && flag==1){
				puts("NO");
				return 0;
			}
		}
		if(i==26){
			puts("YES");
			return 0;
		}
	}
	else if(len%2==0){
		for(i=0;i<26;i++){
			if(alph[i]%2==0){
				continue;
			}
			else if(alph[i]%2!=0){
				puts("NO");
				return 0;
			}
		}
		if(i==26){
			puts("YES");
			return 0;
		}
	}
	free(alph);
	return 0;
}
