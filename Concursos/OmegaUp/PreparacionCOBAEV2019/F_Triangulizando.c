#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {
    float x, y, z;
    scanf("%f %f %f", &x, &y, &z);
    if(x <= 0 || y <= 0 || z <= 0) printf("NO PROFESOR\n");
    else {
        if(x == y && y == z) printf("EQUILATERO\n");
        else if(x == y || x == z || y == z) printf("ISOSCELES\n");
        else printf("ESCALENO\n");
    }
    return 0;
}
