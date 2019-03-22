#include <stdlib.h>
#include <stdio.h>

int main(int argc, char const *argv[]) {
    int n;
    scanf("%d", &n);
    int numDigitos = 0, dig;

    while(n > 0) {
        dig = n % 10;
        n /= 10;
        if(dig % 2 == 0) numDigitos++;
    }

    if(numDigitos % 2 == 0) printf("SI\n");
    else printf("NO\n");

    return 0;
}
