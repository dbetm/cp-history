#include <bits/stdc++.h>
using namespace std;
// https://omegaup.com/arena/problem/Primo-o-Compuesto#problems
#define tam 1000000

bool A[tam];
void generarCriba();

int main(int argc, char const *argv[]) {
    int n;
    cin >> n;
    // el 0 y el 1 no son primos
    A[0] = 1;
    A[1] = 1;
    generarCriba();
    if(A[n] == 0) cout << "PRIMO" << endl;
    else cout << "COMPUESTO" << endl;
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
