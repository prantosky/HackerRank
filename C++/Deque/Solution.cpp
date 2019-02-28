#include <deque>
#include <iostream>
#include <limits>
#include <vector>
using namespace std;

int max(const deque<int>::iterator begin, const deque<int>::iterator end) {
    int maxVal = numeric_limits<int>::min();
    deque<int>::iterator it = begin;
    while (it != end) {
        maxVal = max(maxVal, *it++);
    }
    return maxVal;
}

void printKMax(int arr[], int n, int k) {
    vector<int> maxNums;
    int maxVal = numeric_limits<int>::min();
    deque<int> deque;
    int first = 0;
    for (int i = 0; i < n; i++) {
        if (i < k) {
            deque.push_back(arr[i]);
            maxVal = max(maxVal, arr[i]);
            if (i == k - 1) cout << maxVal << " ";
        } else {
            deque.push_back(arr[i]);
            first = deque.front();
            deque.pop_front();
            if (arr[i] > maxVal) {
                maxVal = arr[i];
            } else if (first == maxVal)
                maxVal = max(deque.begin(), deque.end());
            maxNums.push_back(maxVal);
        }
    }
    for (int x : maxNums) {
        cout << x << " ";
    }
    cout << endl;
}

int main() {
    int t;
    cin >> t;
    while (t > 0) {
        int n, k;
        cin >> n >> k;
        int i;
        int arr[n];
        for (i = 0; i < n; i++) cin >> arr[i];
        printKMax(arr, n, k);
        t--;
    }
    return 0;
}
