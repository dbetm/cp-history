#include <stdio.h>
// https://omegaup.com/arena/problem/MC-Dinero#problems
int main(int argc, char const *argv[]) {
    int n, aux = 1;
    scanf("%d", &n);

    while(aux <= n) {
        for (int i = 0; i < aux; i++) printf("$");
        printf("\n");
        aux++;
    }
    aux = n-1;
    while(aux > 0) {
        for (int i = 0; i < aux; i++) printf("$");
        printf("\n");
        aux--;
    }

    return 0;
}
