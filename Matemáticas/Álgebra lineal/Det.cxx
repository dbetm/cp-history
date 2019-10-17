#include <iostream>
#include <cmath>

using namespace std;
const double EPSILON = 1E-9;

int main() {
    int n = 3;
    double a[][3] = {{1,1,1}, {0, 2, 5}, {5,5,1}};
    //double val1, val2;

    double det = 1;
    for (int i=0; i < n; ++i) {
        int k = i;
        for (int j=i+1; j<n; ++j)
            if (abs(a[j][i]) > abs(a[k][i]))
                k = j;
        if (abs (a[k][i]) < EPSILON) {
            det = 0;
            break;
        }
        // Intercambiar las filas a[i] y a[k]
        double aux[n];
        for (int r = 0; r < n; r++) {
            printf("%f ", a[i][r]);
            aux[r] = a[i][r];
            a[i][r] = a[k][r];
        }
        printf("\n");
        for (int p = 0; p < n; p++) {
            a[k][p] = aux[p];
            printf("%f ", a[k][p]);
        }
        printf("\n");
        // Fin del intercambio de filas

        if (i != k)
            det = -det;
        det *= a[i][i];
        for (int j=i+1; j<n; ++j) {
            a[i][j] /= a[i][i];
        }
        for (int j=0; j<n; ++j)
            if (j != i && abs (a[j][i]) > EPSILON)
                for (int k=i+1; k<n; ++k)
                    a[j][k] -= a[i][k] * a[j][i];
    }

    printf("%f\n", det);

    return 0;
}
