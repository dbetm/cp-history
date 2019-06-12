#include <stdio.h>
// https://omegaup.com/arena/problem/Cuantos-valen-7#problems
int main() {
    int num1, num2;
    scanf("%d %d", &num1, &num2);
    short cont = 0;
    if(num1 == 7) cont++;
    if(num2 == 7) cont++;

    printf("%hd\n", cont);
    return 0;
}
