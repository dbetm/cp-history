#include <bits/stdc++.h>
// Parcialmente correcta
using namespace std;

int main() {
    int a1, a2, a3, a4, a5, a6, a7, a8, a9;
    int a[6] = {0};
    int mayor = INT_MIN;
    cin >> a1 >> a2 >> a3 >> a4 >> a5 >> a6 >> a7 >> a8 >> a9;
    a[0] = a3+a6+a9;
    mayor = max(a[0], mayor);
    a[1] = a2+a5+a8;
    mayor = max(a[1], mayor);
    a[2] = a1+a4+a7;
    mayor = max(a[2], mayor);
    a[3] = a7+a8+a9;
    mayor = max(a[3], mayor);
    a[4] = a4+a5+a6;
    mayor = max(a[4], mayor);
    a[5] = a1+a2+a3;
    mayor = max(a[5], mayor);

    for (int i = 0; i < 6; i++) {
        if(a[i] == mayor) cout << i+1 << " ";
    }
    cout << endl;

    return 0;
}
