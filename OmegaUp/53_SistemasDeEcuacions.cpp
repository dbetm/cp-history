#include <bits/stdc++.h>
// https://omegaup.com/arena/problem/Sistemas-de-ecuaciones-1sol#problems
using namespace std;

int main() {
    double a1, b1, c1, a2, b2, c2, x, y;
    cin >> a1 >> b1 >> c1 >> a2 >> b2 >> c2;

    y = (a1*c2 - a2*c1) / (a1*b2 - a2*b1);

    x = (c1 - (b1 * y)) / a1;

    printf("%0.6lf %0.6lf\n",x, y);
    return 0;
}
