#include <bits/stdc++.h>

using namespace std;
#define watch(x) cout << (#x) << " is " << (x) << " ";

int main() {
    int l, a, n, x, y, cont = 0;
    cin >> l >> a;
    bool carcel[l][a];
    memset(carcel, false, sizeof(carcel));
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        carcel[l-x][y-1] = true;
    }
    bool aux1, aux2;
    // sliding
    for (int i = 0; i < l-1; i++) {
        for (int j = 0; j < a-1; j++) {
            aux1 = !carcel[i][j] && !carcel[i+1][j];
            aux2 = !carcel[i][j+1] && !carcel[i+1][j+1];
            if(aux1 && aux2) cont++;
        }
    }

    cout << cont << endl;

    return 0;
}
