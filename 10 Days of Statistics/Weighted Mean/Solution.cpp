#include <iomanip>
#include <iostream>
using namespace std;


int main() {
    int n;
    cin>>n;
    int array[n];
    for(int i=0;i<n;i++){
        cin>>array[i];
    }
    int w,sum=0,wsum=0;
    
    for(int i=0;i<n;i++){
        cin>>w;
        wsum+=w;
        sum+=(w*array[i]);
    }
    cout<<setprecision(1)<<fixed<<(float)sum/wsum<<endl;
}