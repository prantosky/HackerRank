#include <iostream>
#include <stack>
#include <vector>
using namespace std;

vector<int> getPrimes(int n) {
    vector<int> primes;
    primes.push_back(2);
    n--;
    int num = 3;
    bool flag;
    while (n > 0) {
        flag = false;
        for (const auto &prime : primes) {
            if (num % prime == 0) {
                flag = true;
                break;
            }
        }
        if (!flag) {
            primes.push_back(num);
            n--;
        }
        num += 2;
    }
    return primes;
}

void clearStack(stack<int> &s) {
    while (!s.empty()) {
        s.pop();
    }
}

void printStack(stack<int> &s) {
    while (!s.empty()) {
        cout << s.top() << '\n';
        s.pop();
    }
}

void copyStack(stack<int> &from, stack<int> &to) {
    for (size_t i = 0; i < from.size(); i++) {
        to.push(from.top());
        from.pop();
    }
}

int main(int argc, char const *argv[]) {
    stack<int> a, b, a_aux;
    size_t n, q;
    cin >> n >> q;
    int num;
    for (size_t i = 0; i < n; i++) {
        cin >> num;
        a.push(num);
    }
    vector<int> primes(getPrimes(q));
    for (size_t i = 1; i <= q; i++) {
        while (!a.empty()) {
            if (a.top() % primes.at(i - 1) == 0) {
                b.push(a.top());
            } else {
                a_aux.push(a.top());
            }
            a.pop();
        }
        a = a_aux;
        if (!b.empty()) {
            printStack(b);
        }
        clearStack(a_aux);
    }
    if (!a.empty()) printStack(a);
    return 0;
}
