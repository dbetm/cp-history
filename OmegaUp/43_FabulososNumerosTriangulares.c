#include <stdio.h>
#include <stdlib.h>
// https://omegaup.com/arena/problem/Fabulosos-numeros-triangulares#problems
typedef unsigned long long int ulli;

void mostrarNumeroTriangular(ulli n) {
    ulli res = (n * (n+1)) / 2;
    printf("%llu\n", res);
}

int main() {
    ulli n, ni;

    scanf("%llu", &n);

    while(n--) {
        scanf("%llu", &ni);
        mostrarNumeroTriangular(ni);
    }

    return 0;
}
