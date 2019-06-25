#include <stdio.h>

typedef long long int lli;

int main() {
    lli n, k;
    scanf("%lld %lld",&n, &k);
    lli a[2][n];

    for (int i = 0; i < n; i++) {
        scanf("%lld",&a[0][i]);
    }

    for (int i = 1; i <= k; i++) {
        if(i & 1) {
            a[1][0] = (a[0][1] + a[0][n-1]) % 100;
            a[1][n-1] = (a[0][n-2] + a[0][0]) % 100;
            printf("%lld ", a[0][0]);
            for (int j = 1; j < n-1; j++) {
                a[1][j] = (a[0][j-1] + a[0][j+1]) % 100;
                printf("%lld ", a[0][j]);
            }
            printf("%lld\n", a[0][n-1]);
        }
        else {
            a[0][0] = (a[1][1] + a[1][n-1]) % 100;
            a[0][n-1] = (a[1][n-2] + a[1][0]) % 100;
            printf("%lld ", a[1][0]);
            for (int j = 1; j < n-1; j++) {
                a[0][j] = (a[1][j-1] + a[1][j+1]) % 100;
                printf("%lld ", a[1][j]);
            }
            printf("%lld\n", a[1][n-1]);
        }
    }
    printf("-----------\n");
    if(k & 1) {
        for (int i = 0; i < n; i++) {
            printf("%lld ", a[1][i]);
        }
    }
    else {
        for (int i = 0; i < n; i++) {
            printf("%lld ", a[0][i]);
        }
    }

    printf("\n");

    return 0;
}
