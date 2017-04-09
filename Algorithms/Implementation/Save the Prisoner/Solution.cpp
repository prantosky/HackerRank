#include<iostream>
using namespace std;
int main(){
    int test,n,m,s;
    cin>>test;
    while(test--){
        cin>>n>>m>>s;
        if(m+s-1<n){
            cout<<m+s-1<<endl;
        }
        else{
            if((m+s-1)%n==0)
                cout<<n<<endl;
            else
                cout<<(m+s-1)%n<<endl;
        }
    }
    return 0;
}