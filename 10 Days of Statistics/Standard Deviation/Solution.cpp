#include <cmath>
#include <iostream>
#include<iomanip>
using namespace std;


int main() {
    int n,mean=0;
    float sigma=0;
    cin>>n;
    int array[n];
    for(int i=0;i<n;i++){
        cin>>array[i];
        mean+=array[i];
    }
    mean/=n;
    for(int i=0;i<n;i++){
        sigma+=pow((float)array[i]-mean,2);
    }
    sigma/=n;
    sigma=sqrt(sigma);
    cout<<setprecision(1)<<fixed<<sigma;
    return 0;
}