#include <bits/stdc++.h>

using namespace std;

int main() {
    map<int, uint64_t> numeros;
    int n, m;
    uint64_t num;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> num;
        try {
            numeros[num]++;
        }
        catch(...) {
            pair<int, uint64_t> par;
            par.first = num;
            par.second = 0;
            numeros.insert(par);
        }
    }
    while(m--) {
        cin >> num;
        try {
            cout << num << " " << numeros[num] << endl;
        }
        catch(...) {
            cout << num << " " << -1 << endl;
        }
    }
    return 0;
}
