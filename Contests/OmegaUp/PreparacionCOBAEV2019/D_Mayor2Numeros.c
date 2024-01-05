#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {
    long long int a, b;
    scanf("%lld %lld", &a, &b);

    if(a > b) printf("%lld\n", a);
    else printf("%lld\n", b);

    return 0;
}
