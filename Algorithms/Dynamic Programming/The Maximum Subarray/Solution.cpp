#include <iostream>
#include <limits>
#define endl '\n'

using std::cin, std::cout;

int max(int a, int b, int c) {
    int max = a;
    if (max < b || max < c) {
        max = b;
        if (max < c) max = c;
    }
    return max;
}

int maxSubarrayCrossing(int A[], int low, int mid, int high) {
    int leftSum = std::numeric_limits<int>::min();
    int sum = 0;
    for (int i = mid; i >= low; i--) {
        sum += A[i];
        if (sum > leftSum) {
            leftSum = sum;
        }
    }
    int rightSum = 0;
    sum = 0;
    for (int i = mid + 1; i <= high; i++) {
        sum += A[i];
        if (sum > rightSum) {
            rightSum = sum;
        }
    }
    return leftSum + rightSum;
}

int subarray(int A[], int low, int high) {
    if (low == high)
        return A[low];
    else {
        int mid = (low + high) / 2;
        int left = subarray(A, low, mid);
        int right = subarray(A, mid + 1, high);
        int crossing = maxSubarrayCrossing(A, low, mid, high);
        return max(left, right, crossing);
    }
}

int cornerCase(int A[], int size) {
    bool positiveFlag = false;
    int maxNeg = std::numeric_limits<int>::min();
    for (int i = 0; i < size; i++) {
        if (A[i] < 0 and A[i] > maxNeg) maxNeg = A[i];
        if (A[i] > 0) {
            positiveFlag = true;
            break;
        }
    }
    if (!positiveFlag)
        return maxNeg;
    else
        return false;
}

int subsequence(int A[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        if (A[i] > 0) sum += A[i];
    }
    return sum;
}

int main(int argc, char const *argv[]) {
    int cases;
    cin >> cases;
    int *A, n;
    for (int i = 0; i < cases; i++) {
        cin >> n;
        A = new int[n];
        for (int j = 0; j < n; j++) {
            cin >> A[j];
        }
        if (n == 1) {
            cout << A[0] << " " << A[0] << endl;
        } else if (int value = cornerCase(A, n)) {
            cout << value << " " << value << endl;
        } else {
            int subarraySum = subarray(A, 0, n - 1);
            int subsequenceSum = subsequence(A, n);
            cout << subarraySum << " " << subsequenceSum << endl;
        }
        delete[] A;
    }
    return 0;
}
