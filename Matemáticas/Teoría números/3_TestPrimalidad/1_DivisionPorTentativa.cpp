#include <bits/stdc++.h>

using namespace std;

bool divisionPorTentativa(int n) {
    bool ans = true;
    for (int i = 2; i <= sqrt(n); i++) {
        if(n % i == 0) {
            ans = false;
            break;
        }
    }
    return ans;
}

int main(int argc, char const *argv[]) {
    int n;
    cout << "Escribe en: ";
    cin >> n;
    if(divisionPorTentativa(n)) cout << "Es primo" << endl;
    else cout << "No es primo" << endl;
    return 0;
}
