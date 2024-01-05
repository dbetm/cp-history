#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[]) {
    int r, c;
    scanf("%d %d\n", &r, &c);
    char c2[r][c];

    for (int i = 0, j = r-1; i < r; i++, j--) {
        scanf("%s", c2[i]);
    }
    int cont2 = r-1;
    for (int i = 0; i < 2*r; i++) {
        int cont1 = 0;
        int cont3 = 0;
        for (int j = 0; j < 2*c; j++) {
            if(i < r && j < c) { // cuadrante 2
                printf("%c", c2[i][j]);
            }
            else if(i < r && j >= c) { // cuadrante 1
                cont1++;
                printf("%c", c2[i][c-cont1]);
            }
            else if(i >= r && j < c) { // cuadrante3
                printf("%c", c2[cont2][j]);
            }
            else { // cuadrante 4
                cont3++;
                printf("%c", c2[cont2][c-cont3]);
            }
        }
        if(i >= r) cont2--;
        printf("\n");
    }

    return 0;
}
