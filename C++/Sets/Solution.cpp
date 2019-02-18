#include <iostream>
#include <set>
using namespace std;

int main(int argc, char const *argv[]) {
    int option, num, queries;
    set<int> s;
    set<int>::iterator it;
    cin >> queries;
    for (size_t i = 0; i < queries; i++) {
        cin >> option >> num;
        switch (option) {
            case 1:
                s.insert(num);
                break;
            case 2:
                s.erase(num);
                break;
            case 3:
                it = s.find(num);
                if (it != s.end())
                    cout << "Yes\n";
                else
                    cout << "No\n";
                break;
        }
    }

    return 0;
}
