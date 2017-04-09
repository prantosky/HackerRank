#include<stdio.h>
int main(){
	int test, n,a,b,ans[1000];
	register int i,j;
	scanf("%d",&test);
	while (test--){
		scanf("%d%d%d",&n,&a,&b);
		if(a>b){
            a=a+b;
            b=a-b;
            a=a-b;
        }
		for(i=0;i<n;i++){
			ans[i]=a*(n-1-i)+b*i;
		}
		for(i=0;i<n;i++){
            if(ans[i]==0){
                continue;
            }
            for(j=i+1;j<n;j++){
                if(ans[j]==0){
                    continue;
                }else if(ans[i]==ans[j]){
                    ans[j]=0;
                }
            }
        }
		for(i=0;i<n;i++){
		    if(ans[i])
			printf("%d ",ans[i]);
		}
		puts("");
	}
	return 0;
}