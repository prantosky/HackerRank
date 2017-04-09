#include<stdio.h>
#include<stdlib.h>
int main(){
	int n,t ,x,y,temp;
	int *array; 
	register int i;
	scanf("%d%d",&n, &t);
	array=(int*)malloc(n*sizeof(int));
	if(array==NULL){
		puts("Error Allocating memory");
		return -1;
	}
	for(i=0;i<n;i++){
		scanf("%d",&array[i]);
	}
	while(t--){
		temp =3;
		scanf("%d%d",&x, &y);
		for(i=x;i<=y;i++){
			if(temp>array[i]){
				temp=array[i];
			}
		}
		printf("%d\n",temp);
	}
	return 0;
}