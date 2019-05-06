#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
    unsigned int n, k, bCharged, bActual, total = 0;
    cin >> n >> k;
    vector <unsigned int> costs(n);
    for(unsigned int i = 0; i < n; i++) {
        cin >> costs[i];
    }
    cin >> bCharged;

    for(unsigned int i = 0; i < n; i++) {
        if(i != k) total += costs[i];
    }

    bActual = total / 2;
    if(bActual < bCharged) cout << bCharged - bActual << endl;
    else cout << "Bon Appetit" << endl;

    return 0;
}
