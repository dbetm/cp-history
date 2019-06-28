#include <bits/stdc++.h>
// https://omegaup.com/arena/problem/Costales#problems
using namespace std;

int main() {
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    int n, ph; //cont = 0;
    set<int> phNaranjas;
    set<int> phCostales;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> ph;
        phNaranjas.insert(ph);
    }
    // Leer los ph de los tipos de costales
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> ph;
        phCostales.insert(ph);
    }
    int cont = 0;
    for (auto itr = phNaranjas.begin(); itr != phNaranjas.end(); ++itr) {
        auto rr = phCostales.find(*itr);
        if(rr == phCostales.end()) cont++;
    }
    cout << cont << endl;
    return 0;
}
