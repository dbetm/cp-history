#include <stdio.h>
#include <stdlib.h>
// https://codeforces.com/contest/25/problem/A
int main() {
    int n;
    scanf("%d", &n);
    int aux;
    int contImpares = 0, contPares = 0;
    int i;
    int index1 = 0, index2 = 0;

    for (i = 0; i < n; i++) {
        scanf("%d", &aux);
        if(aux % 2 == 0) {
            contPares++;
            if(contPares == 1) index1 = i;
        }
        else {
            contImpares++;
            if(contImpares == 1) index2 = i;
        }

        if((contPares > 1 && contImpares == 1)
            || (contImpares > 1 && contPares == 1))
            break;
    }

    for (int j = i+1; j < n; j++) {
        scanf("%d", &aux);
    }

    if(contPares == 1) printf("%d\n", index1+1);
    else printf("%d\n", index2+1);

    return 0;
}
