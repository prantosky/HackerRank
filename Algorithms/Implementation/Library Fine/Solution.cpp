#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
using namespace std;

int main(){
    int d1,m1,y1;
    int d2,m2,y2;
    cin >> d1 >> m1 >> y1;
    cin >> d2 >> m2 >> y2;
    if(y1-y2>0){
        cout<<"10000"<<endl;
    }
    else if(m1>m2 && y1-y2==0){
        cout<<500*(m1-m2);
    }
    else if(d1-d2>0 && m1-m2==0 && y1-y2==0){
        cout<<15*(d1-d2);
    }
    else
        cout<<"0";
    return 0;
}
