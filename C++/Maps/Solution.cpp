#include <iostream>
#include <map>
using namespace std;

int main(int argc, char const* argv[]) {
    size_t queries;
    int type, marks;
    string name;
    cin >> queries;
    map<string, int> m;
    for (size_t i = 0; i < queries; i++) {
        cin >> type;
        if (type == 1) {
            cin >> name >> marks;
            auto it = m.find(name);
            if (it == m.end())
                m.insert(pair<string, int>(name, marks));
            else
                m[name] += marks;
        } else if (type == 2) {
            cin >> name;
            m.erase(name);
        } else if (type == 3) {
            try {
                cin >> name;
                cout << m.at(name) << '\n';
            } catch (const std::exception& e) {
                cout << 0 << '\n';
            }
        }
    }
    return 0;
}
