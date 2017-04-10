#include<stdio.h>
#include<stdlib.h>

void find(int*,int*,int);
int zero(const int*,int);

int main(){
	int t,*num, *out,flag;
	register int i; 
	scanf("%d",&t);
	num=(int*)malloc(t*sizeof(int));
	out=(int*)malloc(sizeof(int));
	if (num==NULL || out==NULL) {
		puts("Error Allocating Memory");
		return -1;
	}
	for (i=0;i<t;i++)
	scanf(" %d",&num[i]);
	flag= zero(num,t);
	find(num,out,t);
	i=0;
	if (flag==1 || flag==2){
		printf("%d\n",out[0]);
	}
    if (flag==0){
	    printf("0\n");
    }
	return 0;
}

void find(int *num1,int *num2,int n){
	int x, y,temp;
	for (x=0;x<n;x++){
		if (num1[x]==0)
		continue;
		for (y=0;y<n;y++){
			if (x==y)
				continue;
			if (num1[y]==0)
				continue;
			if (num1[y]==num1[x]){
	    		num1[y]=0;
	    		temp=1;
	    	}
    	}
		if (temp==0){
			num2[0]=num1[x];
		}else{
			num1[x]=0;
			temp=0;
		}
	}
}

int zero(const int * array,int n) {
	int j=0,count=0;
    for (;j<n;j++)
		if (array[j]==0)
			count++;
	if (count>1)
		return 1;
	else if (count==1)
		return 0;
	else if(count==0)
		return 2;
    return 2;
}