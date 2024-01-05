#include <bits/stdc++.h>
/*
    El ordenamiento por selección itera sobre las posiciones en el arreglo. Para cada posición, encuentra el índice del valor mínimo en el subarreglo empezando en esa posición. Luego intercambia los valores en la posición y en el índice mínimo.
*/
using namespace std;

void swap(int, int);
int indexOfMinimum(int, int);
void selectionSort(int);
int A[] = {22, 11, 99, 88, 9, 7, 42};

int main(int argc, char const *argv[]) {
    int len = 7;
    selectionSort(len);
    for (int i = 0; i < len; i++) {
        cout << A[i] << " ";
    }
    cout << endl;
    return 0;
}

// Intercambiar de índice dos elementos del arreglo
void swap(int firstIndex, int secondIndex) {
    int temp = A[firstIndex];
    A[firstIndex] = A[secondIndex];
    A[secondIndex] = temp;
}

// Encuentra el índice del elemento mínimo en el subarreglo
int indexOfMinimum(int startIndex, int len) {
    int minValue = A[startIndex];
    int minIndex = startIndex;

    for (int i = minIndex + 1; i < len; i++) {
        if(A[i] < minValue) {
            minIndex = i;
            minValue = A[i];
        }
    }
    return minIndex;
}

// Ordenamiento por selección
void selectionSort(int len) {
    int ref;
    for (int i = 0; i < len; i++) {
        ref = indexOfMinimum(i, len);
        swap(i, ref);
    }
}
