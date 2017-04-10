#include <stdio.h>

int main(){
    int test,n,count,temp;
    register int i;
    scanf("%d",&test);
    while(test--){
        scanf("%d",&n);
        temp=n;
        count=0;
        while(n){
            if(n%3==0){
                break;
            }
            if(n>=5){
                n-=5;
                count++;
            }else{
                printf("-1");
                goto lab;
            }
        }
        for(i=0;i<n/3;i++){
            printf("555");
        }
        for(i=0;i<count;i++){
            printf("33333");
        }
        lab :
        {}
        puts("");
    }
    return 0;
}