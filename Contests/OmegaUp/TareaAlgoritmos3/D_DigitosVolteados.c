#include <stdlib.h>
#include <stdio.h>

int main(int argc, char const *argv[]) {
    int n, k;
    int bit;
    scanf("%d %d", &n, &k);
    if(n == 1) {
        scanf("%d", &bit);
        printf("%d\n", bit);
    }
    else {
        int a[n];
        // leemos los primeros 2
        scanf("%d %d", &a[0], &a[1]);
        if(a[0] == 0 && a[1] == 1) {
            a[0] = 0;
            a[1] = 0;
            k--;
        }

        for (int i = 2; i < n; i++) {
            scanf("%d", &a[i]);
            if(k != 0) {
                if(i & 1 && a[i] == 1 && a[i-1] == 0) {
                    a[i] = 0;
                    a[i-1] = 0;
                    k--;
                }
                else if(a[i] == 1 && a[i-1] == 0 && a[i-2] == 0) {
                    k %= 2;
                    if(k == 1) {
                        a[i] = 1;
                        a[i-1] = 1;
                    }
                    k = 0;
                }
                else if(a[i] == 1 && a[i-1] == 0) {
                    a[i] = 1;
                    a[i-1] = 1;
                    k--;
                }
            }
        }

        for (int i = 0; i < n-1; i++) {
            printf("%d ", a[i]);
        }
        printf("%d\n", a[n-1]);
    }
    return 0;
}
