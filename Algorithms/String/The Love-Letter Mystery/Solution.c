#include<stdio.h>
#include<string.h>

int main()
{
	int i,j,n,b=0,t,x,count=0;
	char s[10001];scanf("%d",&t);
	for(x=0;x<t+1;x++){ 
		gets(s);
		n=strlen(s);
		for(i=0;i<(n/2);i++){
			if(s[i]==s[n-i-1]){
	  			continue;
	  		}else{
	  			for(j=n-i-1;;){
					if(s[i]==s[j]) {
			  			break;
			  		}else if(s[i]>s[j]){
			  			s[i]=s[i]-1; b++;
			  		}else {s[j]=s[j]-1;b++;}
				}
	  		}
		}
		if(b!=0) printf("%d\n",b);
		else if(b==0 && count>0)
			printf("%d\n",b);
		else if(b==0 && count==0){
			count++;
		}
		b=0;
	}
	return 0;
}