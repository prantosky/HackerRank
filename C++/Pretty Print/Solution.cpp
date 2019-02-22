#include <iomanip>
#include <iostream>
using namespace std;

int main() {
    int T;
    cin >> T;
    cout << setiosflags(ios::uppercase);
    cout << setw(0xf) << internal;
    while (T--) {
        double A;
        cin >> A;
        double B;
        cin >> B;
        double C;
        cin >> C;
        cout << setw(0x0) << right;
        cout << resetiosflags(ios::uppercase);
        cout << "0x" << fixed << hex << setw(0) << static_cast<long long>(A)
             << '\n';
        cout << showpos << fixed << setprecision(2) << setw(15) << setfill('_')
             << B << '\n';
        cout << setiosflags(ios::uppercase);
        cout << scientific << noshowpos << setprecision(9) << C << '\n';
    }
    return 0;
}