#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main() {
    int array[26],array1[26];
    bool flag;
    if(array==NULL || array1==NULL){
        exit(EXIT_FAILURE);
    }
    string str1,str2;
    int test;
    cin>>test;
    while(test--){
        for(register int i=0;i<26;++i){
            array[i]=0;
            array1[i]=0;
        }
        flag=true;
        cin.clear();
        cin>>str1;
        cin.clear();
        cin>>str2;
        for(register int i=0;i<str1.size();++i){
            array[tolower(str1[i])-'a']++;
        }
        for(register int i=0;i<str2.size();++i){
            array1[tolower(str2[i])-'a']++;
        }
        for(register int i=0;i<26;++i){
            if(array[i]!=0 && array1[i]!=0){
                cout<<"YES"<<endl;
                flag=false;
                break;
            }
        }
        if(flag){
            cout<<"NO"<<endl;
        }
    }
    return 0;
}