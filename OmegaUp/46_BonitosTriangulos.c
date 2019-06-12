#include <stdio.h>

typedef long int li;

int main() {
    li base, altura;
    scanf("%ld %ld", &base, &altura);
    printf("%ld\n", (base * altura) / 2);
    return 0;
}
