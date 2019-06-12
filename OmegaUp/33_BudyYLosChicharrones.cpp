#include <bits/stdc++.h>

using namespace std;

int main() {
    double a1, b1, c1;
    double a = 1, b, c;
    scanf("(x+%lf)(x+%lf)=%lf",&a1, &b1, &c1);
    b = a1 + b1;
    c = (a1 * b1) - c1;
    double dis = sqrt(pow(b, 2) - 4*a*c);
    double x1 = (-b + dis) / 2 * a;
    double x2 = (-b - dis) / 2 * a;
    printf("x1= %0.5lf x2= %0.5lf\n",x1, x2);
    return 0;
}
