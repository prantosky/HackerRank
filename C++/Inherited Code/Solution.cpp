#include <cstring>
#include <exception>
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

class BadLengthException : public exception {
   private:
    int mMsg{0};

   public:
    explicit BadLengthException(int n) : mMsg(n) {}
    ~BadLengthException() {}
    const char *what() const throw() {
        char *str = new char[13];
        strcpy(str, (to_string(mMsg)).c_str());
        return str;
    }
};

bool checkUsername(string username) {
    bool isValid = true;
    int n = username.length();
    if (n < 5) {
        throw BadLengthException(n);
    }
    for (int i = 0; i < n - 1; i++) {
        if (username[i] == 'w' && username[i + 1] == 'w') {
            isValid = false;
        }
    }
    return isValid;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        string username;
        cin >> username;
        try {
            bool isValid = checkUsername(username);
            if (isValid) {
                cout << "Valid" << '\n';
            } else {
                cout << "Invalid" << '\n';
            }
        } catch (BadLengthException e) {
            cout << "Too short: " << e.what() << '\n';
        }
    }
    return 0;
}