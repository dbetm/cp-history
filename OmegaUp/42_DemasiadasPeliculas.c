#include <stdio.h>
#include <stdlib.h>
// https://omegaup.com/arena/problem/Demasiadas-peliculas#problems
typedef unsigned long long int ulli;

int main() {
    ulli m, n, ni, suma = 0;
    int bandera = 0;
    scanf("%llu", &m);
    scanf("%llu", &n);

    while (n--) {
        scanf("%llu", &ni);
        if(suma + ni > m) {
            bandera = 1;
            break;
        }
        else {
            suma += ni;
        }
    }
    if(bandera == 1) {
        while(n--) {
            scanf("%llu", &ni);
        }
    }

    if(bandera == 1) printf("NO\n");
    else printf("SI\n");

    return 0;
}
