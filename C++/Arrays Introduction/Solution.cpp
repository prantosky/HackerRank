#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    int array[n];
    for (int i = 0; i < n; ++i) {
        cin >> array[i];
    }
    for (int i = n - 1; i >= 0; i--) {
        cout << array[i] << " ";
    }
    cout << endl;
    return 0;
}