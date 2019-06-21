#include <bits/stdc++.h>
// https://omegaup.com/arena/problem/Acumulando-Numeros#problems
using namespace std;

int main() {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int x = n-1;
    while(n--) {
        cout << a[x] << endl;
        x--;
    }
    return 0;
}
