#include <stdio.h>
#include <stdlib.h>
// https://codeforces.com/contest/231/problem/A
int main() {
    int n, m1, m2, m3;
    int cont = 0;

    scanf("%d", &n);

    while(n--) {
        scanf("%d %d %d", &m1, &m2, &m3);
        if(m1 + m2 + m3 > 1) cont++;
    }

    printf("%d\n", cont);
    return 0;
}
