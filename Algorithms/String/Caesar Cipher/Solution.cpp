#include <cctype>
#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    int k;
    cin >> k;
    k%=26;
    for(register int i=0;i<n;i++){
        if(isalpha(s[i])){
            if(isupper(s[i])){
                if(s[i]-('Z'-(k-1))>=0)
                    s[i]=s[i]-'Z'+'A'+k-1;
                else
                    s[i]=s[i]+k;
            }
            else{
                if(s[i]-('z'-(k-1))>=0)
                    s[i]=s[i]-'z'+'a'+k-1;
                else
                    s[i]=s[i]+k;
            }
        }
    }
    cout<<s;
    return 0;
}