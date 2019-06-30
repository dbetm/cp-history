#include <stdio.h>
#include <stdlib.h>
#include <math.h>
// Parcialmente correcta, no sé el motivo
int main() {
    double a, b, c;
    scanf("%lf %lf %lf", &a, &b, &c);
    if(2*a == 0) printf("Impossivel calcular\n");
    else {
        double discriminante = pow(b, 2) - (4.0*a*c);
        if(discriminante < 0) printf("Impossivel calcular\n");
        else {
            double resRaiz = sqrt(discriminante);
            double r1, r2;
            r1 = (-1*b + resRaiz) / (2.0*a);
            r2 = (-1*b - resRaiz) / (2.0*a);
            printf("R1 = %0.5lf", r1);
            printf("\nR2 = %0.5lf", r2);
            printf("\n");
        }
    }
    return 0;
}
