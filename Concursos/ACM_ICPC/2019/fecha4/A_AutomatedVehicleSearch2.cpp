#include <bits/stdc++.h>
// https://www.juezguapa.com/problemas/enunciado/automated-vehicle-search
// Tags: search, implementation, simulation
using namespace std;
#define watch(x) cout << (#x) << " es " << (x) << endl;
#define fastIO ios_base::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL);
int s, n;

int main() {
    fastIO
    int q, id, suma;
    cin >> n >> q;
    s = sqrt(n);

    map<int, int> ids;

    // O(n*log(n))
    for (int i = 0; i < n; i++) {
        cin >> id;
        ids.insert(pair<int, int>(id, i+1));
    }
    // O(q*log(n))
    while(q--) {
        cin >> id;
        map<int, int>::iterator it = ids.find(id);
        if(it != ids.end()) {
            suma = it->second / s;
            if((it->second % s) != 0) {
                suma++; // retroceso
                suma += (it->second % s) + 1;
            }
            cout << suma << endl;
        }
        else cout << -1 << endl;
    }
    return 0;
}
