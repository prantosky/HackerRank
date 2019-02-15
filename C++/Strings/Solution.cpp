#include <iostream>
#include <string>
using namespace std;

int main(int argc, char const *argv[]) {
    string a, b;
    cin >> a >> b;
    cout << a.size() << " " << b.size() << '\n';
    cout << a + b << '\n';
    char temp = a[0];
    a[0] = b[0];
    b[0] = temp;
    cout << a << " " << b << '\n';
    return 0;
}
