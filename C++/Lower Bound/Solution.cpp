#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char const *argv[]) {
    int n, queries;
    int num;
    cin >> n;
    vector<int> vec(n);
    for (size_t i = 0; i < n; i++) cin >> vec[i];
    cin >> queries;
    vector<int>::iterator it;
    for (size_t i = 0; i < queries; i++) {
        cin >> num;
        it = lower_bound(vec.begin(), vec.end(), num);
        if (*it == num)
            cout << "Yes " << it - vec.begin() + 1 << '\n';
        else
            cout << "No " << it - vec.begin() + 1 << "\n";
    }
    return 0;
}
