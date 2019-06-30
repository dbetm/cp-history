#include <stdio.h>
// #include <stdlib.h>
// #include <math.h>
// https://omegaup.com/arena/problem/Que-hora-es-en-segundos#problems
typedef unsigned int ui;
typedef long long int lli;
typedef unsigned long long int ulli;

int main(void) {
    int h, m, s;
    scanf("%d %d %d",&h, &m, &s);
    s += (m*60) + (h*60*60);
    printf("%d\n", s);
    return 0;
}
