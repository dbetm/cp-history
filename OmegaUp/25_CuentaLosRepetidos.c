#include <stdio.h>
#include <stdlib.h>
// Parcialmente correcta
int tabla[19999999+1];

int main() {
    long long int n, m, aux;
    scanf("%lld %lld", &n, &m);
    for (long long int i = 0; i < n; i++) {
        scanf("%lld", &aux);
        tabla[aux]++;
    }

    for (long long int i = 0; i < m; i++) {
        scanf("%lld", &aux);
        printf("%lld %d\n", aux, tabla[aux]);
    }
    return 0;
}
