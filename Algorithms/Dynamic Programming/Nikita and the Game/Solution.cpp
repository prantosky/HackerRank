#include <iostream>
#include<cstdlib>

using namespace std;

int partition(int[],int,int,int,int);

int main(int argc, char const *argv[]){
	int test,size,sum;
	int *array;
	cin>>test;
	while(test--){
        sum=0;
		cin>>size;
		array=(int*)malloc(size*sizeof(int));
		if(array==NULL){
            cout<<"Error Allocating memory";
            exit(EXIT_FAILURE);
		}
		for (int i = 0; i < size; ++i){
			cin>>array[i];
			sum+=array[i];
		}
		cout<<partition(array,0,size-1,0,sum)<<endl;
		free(array);
	}
	return 0;
}

int partition(int *array,int lower,int upper,int level,int sum){
	if (lower==upper)
		return level;
	int sum1=0,sum2=sum;
	for (int i = lower; i <= upper; ++i){
		sum1+=array[i];
		sum2-=array[i];
		if (sum1==sum2){
			int num1=partition(array,lower,i,level+1,sum1);
			int num2=partition(array,i+1,upper,level+1,sum1);
			if (num1>=num2)
				return num1;
			else
				return num2;
		}
	}
	return level;
}