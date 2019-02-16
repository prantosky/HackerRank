#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

class Student {
   private:
    vector<int> score;

   public:
    void input() {
        vector<int> score(5);
        for (size_t i = 0; i < 5; i++) cin >> score[i];
        this->score = score;
    }

    int calculateTotalScore() {
        return accumulate(this->score.begin(), this->score.end(), 0);
    }
};

int main() {
    int n;  // number of students
    cin >> n;
    Student *s = new Student[n];  // an array of n students

    for (int i = 0; i < n; i++) {
        s[i].input();
    }

    // calculate kristen's score
    int kristen_score = s[0].calculateTotalScore();

    // determine how many students scored higher than kristen
    int count = 0;
    for (int i = 1; i < n; i++) {
        int total = s[i].calculateTotalScore();
        if (total > kristen_score) {
            count++;
        }
    }

    // print result
    cout << count;

    return 0;
}
