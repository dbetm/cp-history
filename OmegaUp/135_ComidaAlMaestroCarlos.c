#include <stdio.h>
// https://omegaup.com/arena/problem/Comida-del-maestro-carlos#problems
int main() {
    int a, g, galleta, suma;
    scanf("%d %d", &a, &g);

    while(a--) {
        suma = 0;
        for (int i = 0; i < g; i++) {
            scanf("%d", &galleta);
            suma += galleta;
        }
        printf("%d\n", suma);
    }

    return 0;
}
