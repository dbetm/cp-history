#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {
    int n, aux;
    long sn, sumaParcial = 0;
    scanf("%d", &n);
    sn = (n * (n+1)) / 2;

    for (int i = 1; i < n; i++) {
        scanf("%d", &aux);
        sumaParcial += aux;
    }

    printf("%ld\n", sn - sumaParcial);

    return 0;
}
