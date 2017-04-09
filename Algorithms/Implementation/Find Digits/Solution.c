#include <iostream>
using namespace std;

int main(){
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        int n;
        int count=0;
        cin >> n;
        int temp=n;
        while(temp){
            if(temp%10!=0 && n%(temp%10)==0){
                count++;
            }
            temp/=10;
        }
        cout<<count<<endl;
    }
    return 0;
}
