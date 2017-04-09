#include<stdio.h>
#include<math.h>
int main(){
	int test,first,last,count,num;
	scanf("%d",&test);
	while(test){
        count=0;
		scanf("%d%d",&first,&last);
	    num=(int)sqrt(first);
        if(num*num<first) 
            num++;
        for(;num*num>=first && num*num<=last;num++){
			count++;
		}
		printf("%d\n",count);
		test--;
	}
	return 0;
}
