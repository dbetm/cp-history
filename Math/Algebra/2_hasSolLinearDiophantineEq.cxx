#include <bits/stdc++.h>
/*
A Linear Diophantine Equation (in two variables) is an equation of the general form:
    ax + by = c
    where a, b, c are given integers, and x, y are unknown integers.
*/
using namespace std;

int gcdExtended(int, int, int &, int &);
bool findAnySolution(int, int, int, int &, int &, int &);

int main() {
    int a, b, c;
    int x, y, g; // They will find with gcdExtended
    cout << "Type a, b and c: ";
    cin >> a >> b >> c;
    if(findAnySolution(a, b, c, x, y, g)) {
        cout << "The given Diophantine equation has a solution: " << endl;
        cout << "x is: " << x << " and y is: " << y << endl;
    }
    else cout << "It does not have any solution" << endl;
    return 0;
}
/*
While the Euclidean algorithm calculates only the greatest common divisor (GCD) of
two integers a and b, the extended version also finds a way to represent GCD in
terms of a and b, i.e. coefficients x and y for which:
    ax + by = gcd(a,b)
*/
int gcdExtended(int a, int b, int &x, int &y) {
    if(a == 0) {
        x = 0;
        y = 1;
        return b;
    }

    int x1, y1;
    int d = gcdExtended(b % a, a, x1, y1);
    x = y1 - (b/a) * x1;
    y = x1;
    return d;
}
// Encuentra cualquier solución, si existe al menos una (obviamente).
bool findAnySolution(int a, int b, int c, int &x0, int &y0, int &g) {
    g = gcdExtended(abs(a), abs(b), x0, y0);
    if(c % g) return false;

    x0 *= c/g;
    y0 *= c/g;
    if(a < 0) x0 = -x0;
    if(b < 0) y0 = -y0;
    return true;
}
