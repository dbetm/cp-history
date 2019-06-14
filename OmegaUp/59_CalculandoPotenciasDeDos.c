#include <stdio.h>
#include <math.h>
// https://omegaup.com/arena/problem/Calculando-potencias-de-2#problems
typedef unsigned long long int ulli;

int main() {
    ulli n;
    scanf("%llu", &n);

    ulli res = log2(n);

    printf("%llu\n", res);

    return 0;
}
