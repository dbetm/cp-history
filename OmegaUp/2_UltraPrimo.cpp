#include <bits/stdc++.h>
// No aceptado
using namespace std;
#define tam 10000

bool A[tam];
void generarCriba();

int main(int argc, char const *argv[]) {
    // Usamos la criba de Erastostenes
    // el 0 y el 1 no son primos
    A[0] = 1;
    A[1] = 1;
    generarCriba();

    string num;
    int n;
    // Leemos el número de casos
    cin >> n;
    for (int j = 0; j < n; j++) {
        cin >> num;
        int suma = 0;
        // vamos a sumar
        for (unsigned int i = 0; i < num.size(); i++) {
            suma += (int)(num[i])-48;
        }
        if(A[suma] == 0) cout << "UltraPrimo\n";
        else cout << "No UltraPrimo\n";
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
