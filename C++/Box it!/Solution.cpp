#include <iostream>

using namespace std;
// Implement the class Box
// l,b,h are integers representing the dimensions of the box

// The class should have the following functions :

// Constructors:
// Box();
// Box(int,int,int);
// Box(Box);

// int getLength(); // Return box's length
// int getBreadth (); // Return box's breadth
// int getHeight ();  //Return box's height
// long long CalculateVolume(); // Return the volume of the box

// Overload operator < as specified
// bool operator<(Box& b)

// Overload operator << as specified
// ostream& operator<<(ostream& out, Box& B)
class Box {
   private:
    int l, b, h;

   public:
    Box() : l(0), b(0), h(0){};
    Box(int l, int b, int h) : l(l), b(b), h(h){};
    Box(const Box& x) {
        l = x.l;
        b = x.b;
        h = x.h;
    };

    Box& operator=(const Box& x) {
        l = x.l;
        b = x.b;
        h = x.h;
        return *this;
    }

    int getLength() { return l; }
    int getBreadth() { return b; }
    int getHeight() { return h; }
    long long CalculateVolume() { return 1LL * l * b * h; }

    friend ostream& operator<<(ostream& os, const Box& b);
    friend bool operator<(const Box& a, const Box& b);
};

ostream& operator<<(ostream& os, const Box& b) {
    os << b.l << " " << b.b << " " << b.h;
    return os;
}

inline bool operator<(const Box& a, const Box& b) {
    if (a.l < b.l)
        return true;
    else if (a.l == b.l and a.b < b.b)
        return true;
    else if (a.l == b.l and a.b == b.b and a.h < b.h)
        return true;
    return false;
}

void check2() {
    int n;
    cin >> n;
    Box temp;
    for (int i = 0; i < n; i++) {
        int type;
        cin >> type;
        if (type == 1) {
            cout << temp << endl;
        }
        if (type == 2) {
            int l, b, h;
            cin >> l >> b >> h;
            Box NewBox(l, b, h);
            temp = NewBox;
            cout << temp << endl;
        }
        if (type == 3) {
            int l, b, h;
            cin >> l >> b >> h;
            Box NewBox(l, b, h);
            if (NewBox < temp) {
                cout << "Lesser\n";
            } else {
                cout << "Greater\n";
            }
        }
        if (type == 4) {
            cout << temp.CalculateVolume() << endl;
        }
        if (type == 5) {
            Box NewBox(temp);
            cout << NewBox << endl;
        }
    }
}

int main() { check2(); }