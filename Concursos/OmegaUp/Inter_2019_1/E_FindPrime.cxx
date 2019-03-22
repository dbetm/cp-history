#include <bits/stdc++.h>
// https://omegaup.com/arena/problem/findprime#problems
using namespace std;

#define tam 10000000
bool A[tam];

void generarCriba();

int main(int argc, char const *argv[]) {
    int n;
    cin >> n;
    // el 0 y el 1 no son primos
    A[0] = 1;
    A[1] = 1;
    generarCriba();
    int cont = 1;
    for (long int i = 2; i < tam; i++) {
        if(A[i] == 0) {
            if(cont == n) {
                cout << i << endl;
                break;
            }
            cont++;
        }
    }

    return 0;
}

void generarCriba() {
    for (int i = 2; i < sqrt(tam); i++) {
        if(A[i] == 0) {
            for (int j = i; j <= (tam / i); j++) {
                A[i*j] = 1;
            }
        }
    }
}
