#include <stdio.h>
#include <stdlib.h>
#include <math.h>
// https://omegaup.com/arena/problem/Evaluando-formulas-en-sucesion#problems
int main() {
    double x, y, z;
    scanf("%lf", &x);
    y = (x + 5) / (2 * (x + 1));
    z = (pow(y, 2) + (x * (x - 2 * y))) / (x * y);
    printf("%0.6lf\n", z);
    return 0;
}
