#include <cstdio>
#include <iostream>
#define endl '\n'
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    string array[] = {"zero", "one", "two",   "three", "four",
                      "five", "six", "seven", "eight", "nine"};
    for (int i = a; i <= b; i++) {
        if (i <= 9)
            cout << array[i] << endl;
        else if (i % 2)
            cout << "odd" << endl;
        else
            cout << "even" << endl;
    }
    return 0;
}
