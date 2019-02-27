#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

class Person {
   protected:
    string name;
    int age;

   public:
    virtual void getdata(){};
    virtual void putdata(){};
};

class Professor : public Person {
   protected:
    int cur_id;
    int publications;

   public:
    static int uniqueId;

    Professor() { cur_id = ++uniqueId; }
    void putdata() {
        cout << name << " " << age << " " << publications << " " << cur_id
             << '\n';
    }

    void getdata() {
        cin >> name;
        cin >> age;
        cin >> publications;
    }
};

class Student : public Person {
   protected:
    vector<int> marks;
    int cur_id;

   public:
    static int uniqueId;
    Student() { cur_id = ++uniqueId; }

    void getdata() {
        cin.ignore();
        cin >> name;
        cin >> age;
        int mark;
        for (size_t i = 0; i < 6; i++) {
            cin >> mark;
            marks.push_back(mark);
        }
    }

    void putdata() {
        cout << name << " " << age << " "
             << accumulate(marks.begin(), marks.end(), 0) << " " << cur_id
             << '\n';
    }
};

int Student ::uniqueId = 0;
int Professor ::uniqueId = 0;

int main() {
    int n, val;
    cin >> n;  // The number of objects that is going to be created.
    Person *per[n];

    for (int i = 0; i < n; i++) {
        cin >> val;
        if (val == 1) {
            // If val is 1 current object is of type Professor
            per[i] = new Professor;

        } else
            per[i] = new Student;  // Else the current object is of type Student

        per[i]->getdata();  // Get the data from the user.
    }

    for (int i = 0; i < n; i++)
        per[i]->putdata();  // Print the required output for each object.

    return 0;
}