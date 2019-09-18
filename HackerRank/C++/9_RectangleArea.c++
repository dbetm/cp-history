#include <iostream>
// https://www.hackerrank.com/challenges/rectangle-area/problem
using namespace std;

class Rectangle {
    protected:
        int width;
        int height;
    public:
        Rectangle() {}
        void display() {
            cout << width << " " << height << endl;
        }
        ~Rectangle() {}
};

class RectangleArea : public Rectangle {
    public:
        void read_input() {
            cin >> width >> height;
        }
        // Sobreescritura
        void display() {
            cout << (width * height) << endl;
        }
};


int main() {
    /*
     * Declare a RectangleArea object
     */
    RectangleArea r_area;

    /*
     * Read the width and height
     */
    r_area.read_input();

    /*
     * Print the width and height
     */
    r_area.Rectangle::display();

    /*
     * Print the area
     */
    r_area.display();

    return 0;
}
