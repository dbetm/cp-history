#include <iostream>
// https://www.hackerrank.com/challenges/cpp-class-template-specialization/problem
using namespace std;

enum class Fruit { apple, orange, pear };
enum class Color { red, green, orange };

template <typename T> struct Traits;

#include <string>

template <> struct Traits <Fruit> {
    public:
        static string name(int index) {
            switch ((Fruit)index) {
                case Fruit::apple:
                    return "apple";
                case Fruit::orange:
                    return "orange";
                case Fruit::pear:
                    return "pear";
                default:
                    return "unknown";
            }
        }
};

template <> struct Traits <Color> {
    public:
        static string name(int index) {
            switch ((Color)index) {
                case Color::red:
                    return "red";
                case Color::green:
                    return "green";
                case Color::orange:
                    return "orange";
                default:
                    return "unknown";
            }
        }
};

int main() {
	int t = 0;
    cin >> t;

    for (int i=0; i!=t; ++i) {
        int index1;
        cin >> index1;
        int index2;
        cin >> index2;
        cout << Traits<Color>::name(index1) << " ";
        cout << Traits<Fruit>::name(index2) << "\n";
    }
}
