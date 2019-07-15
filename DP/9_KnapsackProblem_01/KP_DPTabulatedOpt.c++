#include <bits/stdc++.h>
// O(n*W) TC
// O(2*W) SC
using namespace std;

int knapSack(int W, int wt[], int val[], int n) {
    // Generamos una matriz de 2*(W+1)
    int arr[2][W+1];
    memset(arr, 0, sizeof(arr));

    // Iteramos por cada artículo
    int i = 0, index, index2;
    while(i < n) {
        if(i % 2 == 0) {
            index = 0;
            index2 = 1;
        }
        else {
            index = 1;
            index2 = 0;
        }
        for (int j = 0; j <= W; ++j) {
            if(wt[i] <= j) { // incluir el elementos
                arr[index][j] = max(val[i] + arr[index2][j-wt[i]], arr[index2][j]);
            }
            else { // No incluirlo
                arr[index][j] = arr[index2][j];
            }
        }
        i++;
    }

    return ((n%2) & 1) ? arr[0][W] : arr[1][W];
}

int main() {
    int n, W;
    cout << "Número de items: ";
    cin >> n;
    int val[n];
    int wt[n];
    cout << "Escribe los pares valor-peso" << endl;
    for (int i = 0; i < n; i++) {
        cin >> val[i] >> wt[i];
    }
    cout << "Escribe el peso máximo de la mochila: ";
    cin >> W;
    cout << knapSack(W, wt, val, n) << endl;
    return 0;
}
