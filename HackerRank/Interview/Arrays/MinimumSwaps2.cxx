#include <bits/stdc++.h>

using namespace std;
// No pasa

void swap(int, int);
int indexOfMinimum(int, int);
void selectionSort(int);
vector<int> A;
int cont = 0;

int main(int argc, char const *argv[]) {
    int n, num;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> num;
        A.push_back(num);
    }
    selectionSort(n);
    cout << ((n & 1) ? cont : cont-1) << endl;
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
            cont++;
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
