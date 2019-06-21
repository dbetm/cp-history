#include <bits/stdc++.h>
// https://omegaup.com/arena/problem/Agregando-Tareas-Reloaded#problems
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, p, index, tiempo;
    cin >> n >> p;
    index = n;
    bool flag = true;
    for (int i = 0; i < n; i++) {
        cin >> tiempo;
        if(tiempo >= p && flag) {
            flag = false;
            index = i;
        }
    }

    cout << n-index << endl;

    return 0;
}
