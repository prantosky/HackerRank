#include <stdio.h>
int main(){
    int test, n, c, m,temp,answer;
    scanf("%d",&test);
    while(test--){
        scanf("%d %d %d",&n,&c,&m);
        answer=n/c;
        if(answer<m){
            printf("%d\n",answer);
            continue;
        }
        else if(answer>=m){
            temp=answer;
        }
        while(temp>=m){
            temp-=m;
            answer++;
            temp++;
        }
        printf("%d\n",answer);
        answer=n=m=c=0;
    }
    return 0;
}