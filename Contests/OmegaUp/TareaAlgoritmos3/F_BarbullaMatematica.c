#include <stdlib.h>
#include <stdio.h>

int main(int argc, char const *argv[]) {
    int n;
    long res = 0;
    scanf("%d", &n);
    
    for (int i = 1; i <= n; i++) {
        res += (i * (i + 1)) / 2;
    }

    printf("%ld\n", res);
    return 0;
}
