#include<stdio.h>
#include<string.h>

int main(){
	int test,len,indx=-1;
	register int i; 
	char array[100006];
	scanf("%d",&test);
	while(test--){
		scanf("%s",array); 
		len=strlen(array);
		for(i=0;i<len/2;i++){
			if(array[i]!=array[len-1-i]){
				if(array[i+1]==array[len-1-i] && array[i+2]==array[len-2-i]){
					indx=i;
				}
				if(array[i]==array[len-2-i] && array[i+1]==array[len-3-i]){
					indx=len-1-i;
				}
				break; 
			}
		}
		printf("%d\n",indx); 
		indx=-1;
	}
	return 0;
}