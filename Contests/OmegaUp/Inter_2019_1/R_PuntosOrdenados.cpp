#include <bits/stdc++.h>
// https://omegaup.com/arena/problem/Puntos-Ordenados#problems
using namespace std;

int main(int argc, char const *argv[]) {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    vector < pair<int,int> > puntos;
    cin >> n;
    int primero, segundo;

    for (int i = 0; i < n; i++) {
        cin >> primero >> segundo;
        puntos.push_back(make_pair(primero, segundo));
    }

    sort(puntos.begin(), puntos.end());

    for (int i = 0; i < n; i++) {
        cout << puntos[i].first << " " << puntos[i].second << endl;
    }

    return 0;
}
