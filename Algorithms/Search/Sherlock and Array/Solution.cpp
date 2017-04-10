#include<iostream>

using namespace std;
int sum(int *,int,int);

int main(int argc, char const *argv[]){
	int test;
    bool flag;
	cin>>test;
	while(test--){
        flag= true;
		int size,sum1=0,sum2=0,temp;
		cin>>size;
		int array[size];
		for (register int i = 0; i < size; ++i){
			cin>>array[i];
			sum1+=array[i];
		}
        if(size==1){
			cout<<"YES"<<endl;
			continue;
		}
		sum2=array[0];
		for (register int i = 1; i < size-1; ++i){
			sum1-=array[i-1];
			sum2+=array[i];
			if(sum1==sum2){
				cout<<"YES"<<endl;
				flag=false;
				break;
			}
		}
		if(flag){
			cout<<"NO"<<endl;
		}
	}
	return 0;
}