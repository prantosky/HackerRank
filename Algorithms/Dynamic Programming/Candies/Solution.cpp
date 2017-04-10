#include <iostream>
#include <climits>

using namespace std;

long long int sum(int candies[],int);

int main(int argc, char const *argv[]){
	int size;
	cin>>size;
	int array[size];
    int candies[size];
	for (int i = 0; i < size; ++i){
		cin>>array[i];
	}
    int num=INT_MAX,candy=1;
    candies[0]=1;
	for(int i=1;i<size;i++){
        if(array[i]>array[i-1]){
            candies[i]=(++candy);
        }
        else{
            candies[i]=1;
            candy=1;
        }
    }
    for(int i = size-1 ; i > 0 ; i--){
        if(array[i-1]>array[i]){
            if(candies[i-1]<=candies[i]){
                candies[i-1]=candies[i]+1;
            }
        }
    }
    cout<<sum(candies,size);
	return 0;
}

long long int sum(int candies[],int size){
    long long int sum=0;
    for(int i=0;i<size;i++){
        sum+=candies[i];
    }
    return sum;
}