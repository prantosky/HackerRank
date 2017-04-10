#include<stdio.h>
#include<string.h>
int main(){
	char a[100001];
	int t,str,ans;
	register int i, j;
	scanf("%d",&t);
	while(t!=0){
		fflush(stdin);
		ans=0;
		scanf("%s",a); 
		str=strlen(a);
		for(i=0;i<(str);i++){
			if(a[i]==0)
			continue;
			for(j=i+1;j<str;j++){
				if(a[j]==a[i]){
					ans++;
					a[j]=0;
				}
				else
				break; 
			}
		}
 	printf("%d\n",ans); 
		t--;
	}
	return 0;
}