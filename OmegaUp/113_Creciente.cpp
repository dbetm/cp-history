#include <bits/stdc++.h>
// https://omegaup.com/arena/problem/Creciente#problems
using namespace std;

int main() {
    int n, actual, anterior;
    bool creciente = true, decreciente = true;
    cin >> n;
    cin >> anterior;
    n--;
    while(n--) {
        cin >> actual;

        if(actual >= anterior) {
            decreciente = false;
        }
        else if(actual <= anterior) {
            creciente = false;
        }

        anterior = actual;
    }

    if(n == 1) cout << "desorden" << endl;
    else if(creciente) cout << "creciente" << endl;
    else if(decreciente) cout << "decreciente" << endl;
    else cout << "desorden" << endl;

    return 0;
}
