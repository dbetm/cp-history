#include <bits/stdc++.h>
// https://www.hackerrank.com/challenges/box-it/problem
using namespace std;
//Implement the class Box
//l,b,h are integers representing the dimensions of the box

// The class should have the following functions :

// Constructors:
// Box();
// Box(int,int,int);
// Box(Box);


// int getLength(); // Return box's length
// int getBreadth (); // Return box's breadth
// int getHeight ();  //Return box's height
// long long CalculateVolume(); // Return the volume of the box

//Overload operator < as specified
//bool operator<(Box& b)

//Overload operator << as specified
//ostream& operator<<(ostream& out, Box& B)
class Box {
    private:
        int l;
        int b;
        int h;
    public:
        Box() {
            this->l = 0;
            this->b = 0;
            this->h = 0;
        }

        Box(int l, int b, int h) {
            this->l = l;
            this->b = b;
            this->h = h;
        }

        Box(Box &b) {
            this->l = b.getLength();
            this->b = b.getBreadth();
            this->h = b.getHeight();
        }

        int getLength() {
            return this->l;
        }

        int getBreadth() {
            return this->b;
        }

        int getHeight() {
            return this->h;
        }

        long long CalculateVolume() {
            return ((long long)this->l * (long long)this->b * (long long)this-> h);
        }

        bool operator< (Box& B) {
            bool case1, case2, case3;
            case1 = this->l < B.getLength();
            case2 = this->b < B.getBreadth() && this->l == B.getLength();
            case3 = this->h < B.getHeight() && this->b == B.getBreadth() && this->l == B.getLength();
            return case1 || case2 || case3;
        }
        // Con friend permite acceder a atributos privados de cierta clase
        friend ostream& operator<< (ostream& output, Box& B) {
            output << B.getLength() << " " << B.getBreadth() << " " << B.getHeight();
            return output;
        }
};

void check2() {
	int n;
	cin >> n;
	Box temp;
	for(int i = 0;i < n;i++) {
		int type;
		cin >> type;
		if(type == 1) cout << temp << endl;
		if(type == 2) {
			int l,b,h;
			cin >> l >> b >> h;
			Box NewBox(l, b, h);
			temp = NewBox;
			cout << temp << endl;
		}
		if(type == 3) {
			int l,b,h;
			cin>>l>>b>>h;
			Box NewBox(l,b,h);
			if(NewBox<temp) cout<<"Lesser\n";
			else cout<<"Greater\n";
		}
		if(type == 4) {
			cout << temp.CalculateVolume() << endl;
		}
		if(type == 5) {
			Box NewBox(temp);
			cout << NewBox << endl;
		}
	}
}

int main() {
	check2();
    return 0;
}
