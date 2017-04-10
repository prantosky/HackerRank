#include <iostream>
#include <cmath>

using namespace std;

double fact(int);
int getAnswer(int);

int main(int argc, char const *argv[]){
	int test,num;
	int fours,rest,ans;
	cin>>test;
	while(test--){
		ans=0;
		cin>>num;
		fours=num/4;
		rest=num%4;
		while(fours){
            //cout<<"fours : "<<fours<<endl;
            //cout<<"rest : "<<rest<<endl;
            ans+=(fact(rest+fours)/(fact(rest)*fact(fours)));
            rest+=4;
            fours--;
            //cout<<"ans : "<<ans<<endl;
		}
		ans++;
		//cout<<endl<<ans<<endl;
		cout<<getAnswer(ans)<<endl;
	}
	return 0;
}

double fact(int num){
	double sum=1;
    for (int i = 1; i <= num; ++i){
    	sum*=i;
    }
    return sum;
}

int isPrime(int num){
	if(num<=1)
		return false;
	else if(num==2)
		return true;
    for(int i=2;i<=(int)sqrt(num);i++){
    	if(num%i==0){
    		return false;
    	}
    }
    return true;
}

int getAnswer(int num){
	int count=0;
	for (int i = 2; i <=num; ++i){
		if (isPrime(i)){
		    //cout<<"Prime : "<<i;
			count++;
		}
	}
	return count;
}