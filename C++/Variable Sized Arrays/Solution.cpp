#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[]) {
    size_t n;
    size_t queries;
    cin >> n >> queries;
    size_t size = 0;
    vector<vector<int>> vec(n);
    for (size_t i = 0; i < n; i++) {
        cin >> size;
        vec[i].reserve(size);
        for (size_t j = 0; j < size; j++) cin >> vec[i][j];
    }
    int x = 0, y = 0;
    for (size_t i = 0; i < queries; i++) {
        cin >> x >> y;
        cout << vec[x][y] << '\n';
    }

    return 0;
}
