#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {
    long long a, b;
    scanf("%lld %lld", &a, &b);

    int cont = 0, multiplo, cont2;
    int iguales = 0;

    do {
        cont2 = 0;
        multiplo = a;
        do {
            if(multiplo == b) {
                cont = 31;
                iguales = 1;
                break;
            }
            multiplo *= 2;
            cont2++;
        } while(cont2 < 31);
        b *= 2;
        cont++;
    } while(cont < 31);

    if(iguales == 1) printf("felizmil\n");
    else printf("tristemil\n");
    return 0;
}
