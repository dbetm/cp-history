#include <stdlib.h>
#include <stdio.h>
// https://www.urionlinejudge.com.br/judge/es/problems/view/1002
#define PI 3.14159

int main() {
    double radio;
    scanf("%lf", &radio);
    double area = PI * radio *radio;
    printf("A=%0.4lf\n", area);
    return 0;
}
