#include <stdio.h>
// Parcialmente correcta
typedef unsigned long long int ulli;
typedef long long int lli;

int main() {
    ulli n, h, b, suma = 0, hi;
    scanf("%llu %llu %llu",&n, &h, &b);
    for (ulli i = 1; i <= n; i++) {
        scanf("%llu",&hi);
        if(hi < h) {
            suma += (h - hi) * i;
        }
    }
    printf("%llu\n", suma);
    return 0;
}
