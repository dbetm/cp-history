#include <bits/stdc++.h>
// https://omegaup.com/arena/problem/Boscosos-Numeros#problems
using namespace std;

int main(int argc, char const *argv[]) {
    char dig;
    int numPares = 0;

    while(cin >> dig) {
        if(dig == '0' || dig == '2' || dig == '4' || dig == '6' || dig == '8')
            numPares++;
    }

    if(numPares & 1) cout << "CHAFA" << endl;
    else cout << "CHIDO" << endl;

    return 0;
}
