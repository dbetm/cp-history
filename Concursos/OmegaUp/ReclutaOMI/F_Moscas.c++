#include <bits/stdc++.h>
// https://omegaup.com/arena/problem/moscas#problems
using namespace std;
#define MAX 60001
int tabla[MAX];

void completar(int l, int r);
void contar(int minL, int maxR);

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int n, l, r;
    int maxR = -1;
    int minL = -1;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> l >> r;
        completar(l, r);
        maxR = max(maxR, r);
        minL = min(minL, l);
    }
    contar(minL, maxR);
    return 0;
}

void completar(int l, int r) {
    for (int i = l; i < r; i++) tabla[i]++;
}

void contar(int minL, int maxR) {
    int maxPoblacion = *max_element(tabla, tabla+maxR);
    cout << maxPoblacion << endl;
    bool open = false;
    for (int i = minL; i <= maxR; i++) {
        if(tabla[i] == maxPoblacion && !open) {
            open = true;
            cout << i << " ";
        }
        else if(open && tabla[i] != maxPoblacion) {
            open = false;
            cout << i << endl;
        }
    }
}
