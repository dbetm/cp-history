#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {
    int n, flag = 0, aux;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &aux);
        if(aux == 8) flag = 1;
    }
    printf("%d\n", flag);
    return 0;
}
