#include <iostream>
using namespace std;

class Rectangle {
   protected:
    int width, height;

   public:
    void display() { cout << width << " " << height << '\n'; }
};

class RectangleArea : public Rectangle {
   public:
    void read_input() {
        cin >> width;
        cin >> height;
    }
    void display() { cout << height * width << '\n'; }
};

int main(int argc, char const *argv[]) {
    RectangleArea rect;
    rect.read_input();
    rect.Rectangle::display();
    rect.display();
}
