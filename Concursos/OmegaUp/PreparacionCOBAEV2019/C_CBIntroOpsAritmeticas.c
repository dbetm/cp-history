#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {
    long long int a, b;
    scanf("%lld %lld", &a, &b);
    printf("%lld\n", a+b);
    printf("%lld\n", a-b);
    printf("%lld\n", a*b);
    printf("%.6f\n", (double)a/(double)b);
    return 0;
}
