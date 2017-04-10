#include <iostream>
#include <stdbool.h>

using namespace std;

int main(int argc, char const *argv[])
{
	int test;
	cin>>test;
	while(test--){
		bool stop=false;
		int money,flavours;
		cin>>money>>flavours;
		int array[flavours];
		for (register int i = 0; (i < flavours); ++i){
			cin>>array[i];
		}
		for (register int i=0 ; i < flavours && !stop; ++i){
			for (register int j = i+1; j < flavours && !stop; ++j){
				if(array[i]+array[j]==money){
					cout<<i+1<<" "<<j+1<<endl;
					stop=true;
				}
			}
		}
	}
	return 0;
}