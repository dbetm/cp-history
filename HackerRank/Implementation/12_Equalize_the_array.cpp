#include <bits/stdc++.h>
// https://www.hackerrank.com/challenges/equality-in-a-array/problem

using namespace std;

int main(int argc, char const *argv[]) {
    int n;
    cin >> n;
    int A[n];
    int HashTable[101];

    memset(HashTable, 0, sizeof HashTable);

    for (int i = 0; i < n; i++) {
        cin >> A[i];
        HashTable[A[i]]++;
    }

    // Obtener el número que más se repite
    int max = HashTable[0];
    int maxIndex; // es el que más veces se repite
    for (int i = 1; i <= 100; i++) {
        if(HashTable[i] > max) {
            max = HashTable[i];
            maxIndex = i;
        }
    }

    // Se cuenta el número de elementos diferentes a maxIndex
    // que son los que se deben eliminar
    int cont = 0;
    for (int i = 0; i < n; i++) {
        if(A[i] != maxIndex) cont++;
    }

    cout << cont << endl;

    return 0;
}
