#include <iostream>
#include <cmath>
#include<iomanip>
using namespace std;

void quicksort(int*,int,int);
int partition(int*,int,int);

int main(int argc, char const *argv[])
{
	int n,sum=0;
	cin>>n;
	int array[n];
	for (int i = 0; i < n; ++i){
		cin>>array[i];
		sum+=array[i];
	}
	cout<<setprecision(1)<<fixed<<(float)sum/n<<endl;
	quicksort(array,0,n-1);
	if (n%2==1){
		cout<<array[n/2];
	}else{
		cout<<((float)array[n/2-1]+array[n/2])/2<<endl;
	}
	int max_count=0;
	int mode=-1;
	int current_count=0;
	int value_current=array[0];
	for (int i = 0; i < n; ++i){
		if (value_current==array[i]){
			current_count++;
		}else{
			if (current_count>max_count){
				max_count=current_count;
				mode=value_current;
			}
            value_current=array[i];
            current_count=1;
		}
	}
	cout<<mode<<endl;
	return 0;
}

void quicksort(int *array,int start,int end)
{
	if (start<end)
	{
		int p=partition(array,start,end);
		quicksort(array,start,p-1);
		quicksort(array,p+1,end);
	}
}

int partition(int *array,int start,int end)
{
	int pivot=array[end];
	int i=start;
	for (register int j = start; j < end; ++j)
	{
		if (array[j]<=pivot)
		{
			int temp=array[i];
			array[i]=array[j];
			array[j]=temp;
			i++;
		}
	}
	int temp=array[i];
	array[i]=array[end];
	array[end]=temp;
	return i;
}