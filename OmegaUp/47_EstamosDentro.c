#include <stdio.h>
#include <math.h>
#include <stdlib.h>
// https://omegaup.com/arena/problem/Estamos-dentro#problems
long int h, k, rExt2, rInt2;
void evaluar(long int x, long int y);

int main() {
    int rExt, rInt, n, xi, yi;
    scanf("%ld %ld %d %d %d",&h, &k, &rExt, &rInt, &n);

    rExt2 = pow((long int)rExt, (long int)2);
    rInt2 = pow((long int)rInt, (long int)2);

    while (n--) {
        scanf("%d %d",&xi, &yi);
        evaluar(xi, yi);
    }
    return 0;
}

void evaluar(long int x, long int y) {
    long int res = pow(x-h, 2) + pow(y-k, 2);
    if(res <= rExt2 && res >= rInt2) printf("Dentro\n");
    else printf("Fuera\n");
}
