#include <stdio.h>
#include <stdlib.h>
#include <math.h>
// https://omegaup.com/arena/problem/Programando-formulas#problems
#define M_PI 3.14159265358979323846

int main() {
    double x, y, z, res;
    scanf("%lf %lf %lf", &x, &y, &z);
    res = x + x*(y + pow(z, 2));
    res /= (x + M_PI) * (y + M_PI);
    printf("%0.6lf\n", res);
    return 0;
}
