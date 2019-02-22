#define io(a) cin >> a
#define toStr(x) #x
#define INF std::numeric_limits<int>::max()
#define FUNCTION(name, operator)              \
    inline void name(int m, int current) {    \
        m = m operator current ? m : current; \
    }
#define foreach(a, b) for (size_t i = 0; i < v.size(); i++)

#include <iostream>
#include <limits>
#include <vector>
using namespace std;

#if !defined toStr || !defined io || !defined FUNCTION || !defined INF
#error Missing preprocessor definitions
#endif

FUNCTION(minimum, <)
FUNCTION(maximum, >)

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    foreach (v, i) { io(v)[i]; }
    int mn = INF;
    int mx = -INF;
    foreach (v, i) {
        minimum(mn, v[i]);
        maximum(mx, v[i]);
    }
    int ans = mx - mn;
    cout << toStr(Result =) << ' ' << ans;
    return 0;
}