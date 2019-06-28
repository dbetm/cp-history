#include <stdio.h>
// https://omegaup.com/arena/problem/Buscar-y-contar#problems
int tabla[1000001];

int main() {
    int n, num, b;
    scanf("%d", &n);
    while(n--) {
        scanf("%d", &num);
        tabla[num]++;
    }
    scanf("%d", &b);
    printf("%d\n", tabla[b]);
    return 0;
}
