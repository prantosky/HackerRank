#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char const *argv[]) {
    int size;
    cin >> size;
    vector<int> vec(size);
    for (size_t i = 0; i < size; i++) cin >> vec[i];
    sort(vec.begin(), vec.end());
    for (auto &x : vec) cout << x << " ";
    cout << '\n';
    return 0;
}
