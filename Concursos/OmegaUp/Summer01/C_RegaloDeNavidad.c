#include <stdio.h>

int main() {
    long int n, totalRegalos;
    scanf("%ld", &n);

    totalRegalos = n / 7;
    totalRegalos += n / 5;

    totalRegalos -=  (n/35);

    printf("%ld\n", totalRegalos);

    return 0;
}
