#include<stdio.h>
int main()
{
	long int test, a, b, x, y, z,answer;
	scanf("%ld",&test);
	while(test--){
		answer=0;
		scanf("%ld%ld",&a, &b) ;
		scanf("%ld%ld%ld",&x, &y, &z);
		if(x==y){
			answer+=2*x*a;
			printf("%ld\n",answer);
			goto lab;
		}
		if(x>y){
			answer+=y*b;
			if(x>y+z){
                answer=answer+(a*(y+z));
            }
            else if(x<=y+z){
                answer=answer+(a*x);
            }
		}
		else if(x<y){
			answer+=x*a;
			if(y>x+z){
                answer=answer+(b*(x+z));
            }
            else if(y<=x+z){
                answer=answer+(b*y);
            }
		}
		printf("%ld\n",answer) ;
		lab :
		{}
		answer=0;
	}
	return 0;
}