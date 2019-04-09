#include <bits/stdc++.h>
// https://omegaup.com/arena/problem/UltraPrimo#problems
using namespace std;

bool esPrimo(int);

int main(int argc, char const *argv[]) {
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
        if(esPrimo(suma)) cout << "UltraPrimo" << endl;
        else cout << "No UltraPrimo" << endl;
    }
    return 0;
}

bool esPrimo(int num) {
    bool ans = true;
    for (int i = 2; i <= sqrt(num); i++) {
        if(num % i == 0) {
            ans = false;
            break;
        }
    }
    return ans;
}
