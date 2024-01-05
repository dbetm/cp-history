#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {
    int n, aux, max = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &aux);
        if(aux > max) max = aux;
    }
    printf("%d\n", max);
    return 0;
}
