#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {
    long long int a, b, c, mayor;
    scanf("%lld", &a);
    mayor = a;
    scanf("%lld", &b);

    if(b > mayor) {
        mayor = b;
    }

    scanf("%lld", &c);

    if(c > mayor) {
        mayor = c;
    }

    printf("%lld\n", mayor);
    return 0;
}
