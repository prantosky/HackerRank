#include<stdio.h>
#include<stdlib.h>

int snum(int *,int,int);
void cuts(int *,int,int); 
int check(int *,int); 

int main(){
	int n,*array, temp,cut,flag=1; 
	register int i; 
	scanf("%d",&n);
	array=(int*)malloc(n*sizeof(int));
	if(array==NULL) {
		puts("Error Allocating memory");
		return -1;
	}
	for(i=0;i<n;i++){
		scanf("%d",&array[i]);
		if(temp<array[i]){
			temp=array[i];
		}
	}
	do{
		cut=snum(array,n,temp);
		cuts(array,n,cut);
		flag=check(array,n);
		
	}while(flag==1);
	return 0;
}

int snum(int *array, int n ,int temp) {
	int x; 
	for(x=0;x<n;x++){
		if(array[x]==0){
			continue;
		}
		if(temp>array[x]){
			temp=array[x];
		}
	}
	return temp; 
}

void cuts(int *array, int n, int cut) {
	int x,count=0; 
	for(x=0;x<n;x++){
		if(array[x]==0){
			continue;
		}
		else
		array[x]-=cut; 
		count++; 
	}
	printf("%d\n",count); 
}

int check(int *array,int n) {
	int i,sum=0; 
	for(i=0;i<n;i++){
		sum+=array[i];
	}
	if(sum==0){
		return 0;
	}
	else
	return 1;
}