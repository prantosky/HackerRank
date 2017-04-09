#include<stdio.h>
#include<stdlib.h>

void getAns(int **,int,int);

int main(){
	int **array,n,m,temp;
	char *str;
	register int i,j=0;
	scanf("%d%d",&n,&m);
	temp=n;
	str=(char*)malloc((m+1)*sizeof(char));
	array=(int**)malloc(n*sizeof(int*));
	if(array==NULL || str==NULL){
		puts("Error Allocating Memory");
		return -1;
	}
	for(i=0;i<n;i++){
		array[i]=(int*)malloc(m*sizeof(int));
		if(array[i]==NULL){
			puts("Error Allocating Memory");
			return -1;
		}
	}
	while(temp--){
		scanf("%s",str);
		for(i=0;j<n && i<m;i++){
			array[j][i]=48-(int)str[i];
			if(array[j][i]<0){
				array[j][i]*=(-1);
			}
		}
		j++;
	}
	getAns(array,n,m);
	return 0;
}

void getAns(int **test,int n,int m){
	int topic=0,count=0,temp1=0,temp2=0;
	register int i,j,a,b;
	for(i=0;i<n;i++){
		for(j=i+1;j<n;j++){
		    temp1=0;
			for(a=0;a<m;a++){
			    temp2=test[i][a]+test[j][a];
				if(temp2>0){
					temp1++;
				}
			}
			if(temp1>topic){
				topic=temp1;
				count=1;
			}
			else if(temp1==topic)			{
				count++;
			}
		}
	}
	printf("%d\n%d",topic,count);
}