#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    int *alpha,len,temp;
    register int i;
    char str[1001];
    fgets(str,1001,stdin);
    len=strlen(str);
    alpha=(int*)calloc(26,sizeof(int));
    if(alpha==NULL){
        puts("Error Allocating Memory");
        return 0;
    }
    for(i=0;i<len;i++){
        if(str[i]==' '){
            continue;
        }
        temp=(int)str[i]-65;
        if(temp>25){
            temp-=32;
        }
        alpha[temp]++;
    }
    for(i=0;i<26;i++){
        if(alpha[i]==0){
            puts("not pangram");
            return 0;
        }
    }
    if(i==26){
        puts("pangram");
    }
    return 0;
}