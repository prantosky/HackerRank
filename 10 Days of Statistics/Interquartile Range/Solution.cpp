#include <cmath>
#include <iomanip>
#include <iostream>
using namespace std;

void quicksort(int array[][2],int,int);
int partition(int array[][2],int,int);
float findMedian(int array[][2],int,int,int);
int getElement(int array[][2],int,int);
void swap(int array[][2],int,int);

int main() {

    int n,temp=0;
    cin>>n;
    int array[n][2];

    for(int i=0;i<n;i++){
        cin>>array[i][0];
    }
    for(int i=0;i<n;i++){
        cin>>array[i][1];
    }

    quicksort(array,0,n-1);
    for (int i = 1; i < n; ++i){
        array[i][1]+=array[i-1][1];
    }

    int size=array[n-1][1];

    float q1,q3;
    q1=findMedian(array,n,0,size/2-1);
    if(size%2==1){
        q3=findMedian(array,n,size/2+1,size-1);
    }else{
        q3=findMedian(array,n,size/2,size-1);
    }

    cout<<setprecision(1)<<fixed<<showpoint<<q3-q1<<endl;
    return 0;
}

float findMedian(int array[][2],int size,int start,int end){
	if ((end-start+1)%2==1){
		return getElement(array,(start+end+1)/2,size);
	}else{
        return ((float)getElement(array,(start+end+1)/2-1,size)+getElement(array,(start+end+1)/2,size))/2;
	}
    return 0;
}

void quicksort(int array[][2],int start,int end){
	if (start<end){
		int p=partition(array,start,end);
		quicksort(array,start,p-1);
		quicksort(array,p+1,end);
	}
}

int partition(int array[][2],int start,int end){
	int pivot=array[end][0];
	int i=start;
	for (register int j = start; j < end; ++j){
		if (array[j][0]<=pivot){
			swap(array,i,j);
			i++;
		}
	}
	swap(array,i,end);
	return i;
}

int getElement(int array[][2],int index,int size){
    int i;
    for (i = 0; array[i][1]-1 < index && i<size ; ++i){
    }
    if(i==-1){
        return array[size-1][0];
    }
    else{
        return array[i][0];
    }
}

void swap(int array[][2],int i,int j){
    int temp=array[i][0];
    array[i][0]=array[j][0];
    array[j][0]=temp;
    temp=array[i][1];
    array[i][1]=array[j][1];
    array[j][1]=temp;
}