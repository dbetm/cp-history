#include <bits/stdc++.h>
// https://omegaup.com/arena/problem/OMI2018-Reforma#problems
using namespace std;

int main(int argc, char const *argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, anterior, actual;
    cin >> n;
    cin >> anterior;
    int k = 1, kaux;

    for (int i = 0; i < n-1; i++) {
        kaux = 1;
        cin >> actual;
        while(actual < anterior) {
            i++;
            anterior = actual;
            kaux++;
            if(i >= n-1) break;
            cin >> actual;
        }
        k = max(k, kaux);
        anterior = actual;
    }

    cout << k << endl;
    return 0;
}
