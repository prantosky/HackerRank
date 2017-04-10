#include<iostream>
#include<string>
#include<cmath>
int main(){
    using namespace std;
    string str;
    int test;
    register int i,j;
    cin>>test;
    while(test--){
        cin>>str;
        j=str.size();
        for(i=0;i<j-1;i++){
            if(abs(str[i+1]-str[i])!=abs(str[j-1-i]-str[j-2-i])){
                cout<<"Not Funny"<<endl;
                break;
            }
        }
        if(i==j-1){
            cout<<"Funny"<<endl;
        }
    }
    return 1;
}