#include <stdio.h>

int main() {
    double volMolar = 22.414, n;
    scanf("%lf", &n);

    printf("%0.3lf l\n", (double)volMolar*(double)n);

    return 0;
}
