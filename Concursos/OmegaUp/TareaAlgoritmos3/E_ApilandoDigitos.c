#include <stdlib.h>
#include <stdio.h>

int main(int argc, char const *argv[]) {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < i; j++) {
            printf("%d", i);
        }
        printf("\n");
    }

    for (int i = n-1; i >= 1; i--) {
        for (int j = 0; j < i; j++) {
            printf("%d", i);
        }
        printf("\n");
    }


    return 0;
}
