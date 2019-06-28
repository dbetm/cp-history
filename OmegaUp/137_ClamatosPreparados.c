#include <stdio.h>
// https://omegaup.com/arena/problem/Clamatos-Preparados#problems
int main(void) {
    int n, radioFrasco;
    int index = -1;
    scanf("%d", &n);
    int llaves[n];

    for (int i = 0; i < n; i++) {
        scanf("%d", &llaves[i]);
    }
    scanf("%d", &radioFrasco);

    for (int i = 0; i < n; i++) {
        if(llaves[i]/2 == radioFrasco) {
            index = i;
            break;
        }
    }

    if(index == -1) printf("No hay ninguna llave de ese tamanio, rompe el frasco como si fuera huevo y asi tomatelo\n");
    else printf("%d %d\n",index+1, llaves[index]);

    return 0;
}
