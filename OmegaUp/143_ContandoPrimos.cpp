#include <bits/stdc++.h>
// Respuesta incorrecta
using namespace std;
int tam, cont = 0;

void generarCriba(vector<int> &arr);

int main() {
    cin >> tam;
    vector<int> A(tam+1);
    generarCriba(A);
    for (int i = 2; i <= tam; i++) {
        if(A[i] == 0) cont++;
    }
    cout << cont << endl;
    return 0;
}

void generarCriba(vector<int> &A) {
    for (int i = 2; i <= sqrt(tam); i++) {
        if(A[i] == 0) {
            for (int j = i; j <= (tam / i); j++) {
                A[i*j] = 1;
            }
        }
    }
}
