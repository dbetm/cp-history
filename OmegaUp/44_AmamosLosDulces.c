#include <stdio.h>
#include <stdlib.h>

typedef unsigned long long int ulli;

int main() {
    ulli n;
    scanf("%llu", &n);

    if(n % 3 == 0) printf("Felicidad pura\n");
    else printf("Pelea segura\n");

    return 0;
}
