#include <bits/stdc++.h>
// https://omegaup.com/arena/problem/Permutacion-de-Primos#problems
using namespace std;

#define MAX 10001
bool A[MAX];
// Respuesta: printf("296962999629\n");
void generarCriba();
bool encontrarSecuencia(int);
int myrandom (int i) { return std::rand()%i;}

int main(int argc, char const *argv[]) {
    // el 0 y el 1 no son primos
    A[0] = 1;
    A[1] = 1;
    generarCriba();
    for (long int i = 1009; i <= 9973; i++) {
        if(A[i] == 0) { // testeamos con cada primo
            if(encontrarSecuencia(i)) break;
        }
        //if(i == 2000) break;
    }
    return 0;
}

bool encontrarSecuencia(int primo) {
    srand ( unsigned (std::time(0)));
    //
    bool ans = false;
    vector <string> permutaciones;
    vector <int> primosPermutacion;
    // obtenemos los primeros 4 digitos
    string original = "";
    for (int i = 0; i < 4; i++) {
        original += to_string(primo%10);
        primo /= 10;
    }
    reverse(original.begin(), original.end());
    permutaciones.push_back(original);
    int cont = 0;
    // generar las demás combinaciones
    while (cont++ < 1000) {
        string num = original;
        random_shuffle(num.begin(),num.end(), myrandom);
        if(find(permutaciones.begin(), permutaciones.end(), num) == permutaciones.end()) {
            permutaciones.push_back(num);
        }
    }
    int x;
    for (unsigned int i = 0; i < permutaciones.size(); i++) {
        stringstream geek(permutaciones[i]);
        geek >> x;
        if(x >= 1009 && x <= 9973 && A[x] == 0) {
            primosPermutacion.push_back(x);
            A[x] = 1; // para ya no volver a buscar después
        }
    }

    if(primosPermutacion.size() >= 3) {
        sort(primosPermutacion.begin(), primosPermutacion.end());
        for (unsigned int i = 2; i < primosPermutacion.size(); i++) {
            int dif = primosPermutacion[i-1] - primosPermutacion[i-2];
            if(primosPermutacion[i] - primosPermutacion[i-1] == dif) {
                cout << primosPermutacion[i-2] << " ";
                cout << primosPermutacion[i-1] << " ";
                cout << primosPermutacion[i] << " ";
                ans = true;
                cout << endl;
            }
        }
    }
    return ans;
}

void generarCriba() {
    for (int i = 2; i < sqrt(MAX); i++) {
        if(A[i] == 0) {
            for (int j = i; j <= (MAX / i); j++) A[i*j] = 1;
        }
    }
}
