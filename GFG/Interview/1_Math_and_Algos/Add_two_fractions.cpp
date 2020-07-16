#include <bits/stdc++.h>
// https://practice.geeksforgeeks.org/problems/add-two-fractions/1/
// Tag(s): Math
using namespace std;

void addFraction(int num1, int den1, int num2, int den2);

int main() {
    int T;
    cin >> T;
    while(T--) {
        int a,b,c,d,resultNum,resultDen;
        cin >> a >> b >> c >> d;
        addFraction(a,b,c,d);
    }
}


/*You are required to complete this function*/
void addFraction(int num1, int den1, int num2,int den2) {
    int numx = num1*den2 + num2*den1;
    int denx = den1 * den2;
    int gcd = __gcd(numx, denx);
    cout << (numx / gcd) << "/" << (denx / gcd) << endl;
}
