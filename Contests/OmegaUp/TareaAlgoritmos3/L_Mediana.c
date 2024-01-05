#include <stdio.h>
#include <stdlib.h>

void sort(float *, int n);

int main(int argc, char const *argv[]) {
    int n;
    scanf("%d", &n);
    float arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%f", &arr[i]);
    }
    sort(&arr[0], n);
    float res = 0;

    if(n & 1) { // impar
        res = arr[n/2];
    }
    else {
        int index = n / 2;
        res = (arr[index] + arr[index-1]) / 2;
    }

    printf("%.1f\n", res);
    return 0;
}

// Burbuja optimizado
void sort(float *A, int n) {
    float temp;
    int swapped;
    for (int i = 0; i < n - 1; i++) {
        swapped = 0;
        for (int j = 0; j < n - i - 1; j++) {
            if(A[j] > A[j + 1]) {
                temp = A[j];
                A[j] = A[j + 1];
                A[j + 1] = temp;
                swapped = 1;
            }
        }
        // Si (por lo menos) dos elementos no fueron intercambiados, entonces sale
        if(!swapped) {
            break;
        }
    }
}
