#include <cmath>
#include <iostream>
using namespace std;

void quicksort(int*,int,int);
int partition(int*,int,int);
float findMedian(int*,int,int);

int main() {
    int n;
    cin>>n;
    int array[n];
    for(int i=0;i<n;i++){
        cin>>array[i];
    }
    quicksort(array,0,n-1);
    int q1,q2,q3;
    q2=findMedian(array,0,n-1);
    if(n%2==1){
        q1=findMedian(array,0,n/2-1);
        q3=findMedian(array,n/2+1,n-1);
    }else{
        q1=findMedian(array,0,n/2-1);
        q3=findMedian(array,n/2,n-1);
    }
    cout<<q1<<endl<<q2<<endl<<q3<<endl;
    return 0;
}

float findMedian(int* array,int start,int end){
	if ((end-start+1)%2==1){
		return array[(start+end+1)/2];
	}else{
		return ((float)array[(start+end+1)/2-1]+array[(start+end+1)/2])/2;
	}
    return 0;
}

void quicksort(int *array,int start,int end){
	if (start<end){
		int p=partition(array,start,end);
		quicksort(array,start,p-1);
		quicksort(array,p+1,end);
	}
}

int partition(int *array,int start,int end){
	int pivot=array[end];
	int i=start;
	for (register int j = start; j < end; ++j){
		if (array[j]<=pivot){
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