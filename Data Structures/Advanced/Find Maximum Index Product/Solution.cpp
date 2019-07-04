#include <iostream>
using namespace std;

int main(int argc, char const *argv[]) {
    int n;
    cin >> n;
    long array[n], inner_product[n];
    for (int i = 0; i < n; i++) {
        cin >> array[i];
        inner_product[i] = 0;
    }
    for (int i = 1; i < n - 1; i++) {
        for (int j = i - 1; j >= 0; j--) {
            if (array[j] > array[i]) {
                inner_product[i] = j + 1;
            } else if (array[i - 1] == array[i]) {
                inner_product[i] = inner_product[i - 1];
            }
            break;
        }
    }
    long max_inner_product = 0;
    for (int i = 1; i < n - 1; i++) {
        if (inner_product[i] != 0)
            for (int j = i + 1; j < n; j++) {
                if (array[j] > array[i]) {
                    inner_product[i] *= j + 1;
                    if (inner_product[i] > max_inner_product) {
                        max_inner_product = inner_product[i];
                    }
                    break;
                }
            }
    }
    cout << max_inner_product << endl;
    return 0;
}
