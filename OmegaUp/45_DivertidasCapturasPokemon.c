#include <stdio.h>
#include <stdlib.h>
// https://omegaup.com/arena/problem/Divertidas-capturas-Pokemon#problems
typedef long long int lli;

int main() {
    lli fuego, planta, agua, gatica = 0, alexander = 0, brandon = 0;
    scanf("%lld %lld %lld", &fuego, &planta, &agua);
    gatica = fuego + (planta * 2) + (agua * 3);
    scanf("%lld %lld %lld", &fuego, &planta, &agua);
    alexander = fuego + (planta * 2) + (agua * 3);
    scanf("%lld %lld %lld", &fuego, &planta, &agua);
    brandon = fuego + (planta * 2) + (agua * 3);

    if(gatica > alexander && gatica > brandon) printf("Gatica\n");
    else if(alexander > gatica && alexander > brandon) printf("Alexander\n");
    else printf("Brandon\n");

    return 0;
}
