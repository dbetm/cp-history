#include <bits/stdc++.h>
// SRC: GFG
// TC: O(n^2) => (2n)^2 + 2n = 4*n^2 + 2*n = 2n*(2*n + 1)
// Space: 0(n)
/*
Given an array arr[0 … n-1] containing n positive integers, a subsequence
of arr[] is called Bitonic if it is first increasing, then decreasing.

A sequence, sorted in increasing order is considered Bitonic with the decreasing
part as empty. Similarly, decreasing order sequence is considered Bitonic
with the increasing part as empty.
*/

using namespace std;
/* LBS regresa la longitud de _Longest Bitonic Subsequence_ en
arr[] de tamaño n. La función crea dos arreglos temporales
lis[] y lds[] y retorna el máximo lis[i] + lds[i] - 1.

-> lis[i] => Longest Increasing Subsequence ending with arr[i]
-> lds[i] => Longest Decresing Subsequence starting with arr[i]
*/
int lbs(int arr[], int n);

int main(int argc, char const *argv[]) {
    int n;
    cout << "Type n: ";
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) cin >> arr[i];
    cout << "Length of LBS is: " << lbs(arr, n) << endl;
    return 0;
}

int lbs(int arr[], int n) {
    int maxi;
    int lis[n];
    int lds[n];
    // Agregar casos base para cada arreglo temporal
    for (int i = 0; i < n; i++) {
        lis[i] = 1;
        lds[i] = 1;
    }

    // Calculamos los valores de LIS de izquierda a derecha
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if(arr[i] > arr[j] && lis[i] < lis[j] + 1) {
                lis[i] = lis[j] + 1;
            }
        }
    }

    // Calcular los valores de LDS de derecha a izquierda
    for (int i = n-2; i >= 0; i--) {
        for (int j = n-1; j > i; j--) {
            if(arr[i] > arr[j] && lds[i] < lds[j] + 1) {
                lds[i] = lds[j] + 1;
            }
        }
    }

    // Recuperar el valor máximo de lis[i] + lds[i] - 1;
    maxi = lis[0] + lds[0] - 1;
    for (int i = 1; i < n; i++) {
        maxi = max(maxi, lis[i] + lds[i] - 1);
    }

    return maxi;
}
