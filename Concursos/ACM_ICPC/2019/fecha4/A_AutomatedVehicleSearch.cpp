#include <bits/stdc++.h>
// https://www.juezguapa.com/problemas/enunciado/automated-vehicle-search
// Tags: search, implementation, simulation
// TC: Big-Omega((n/s)*q)
using namespace std;
#define watch(x) cout << (#x) << " es " << (x) << endl;
#define fastIO ios_base::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL);
vector<int> vehicles;
int s, n;

int proceso(int k);

int main() {
    fastIO
    int q, id;
    cin >> n >> q;
    s = sqrt(n);
    vehicles.push_back(-1);

    for (int i = 0; i < n; i++) {
        cin >> id;
        vehicles.push_back(id);
    }
    while(q--) {
        cin >> id;
        cout << proceso(id) << endl;
    }
    return 0;
}

int proceso(int k) {
    int id = 0;
    int cont = 0;

    while(id <= n && vehicles[id] <= k) {
        id += s;
        cont++;
        if(vehicles[id] == k) return cont;
    }

    id -= s;
    cont++;

    while(id <= n && vehicles[id] <= k) {
        id++;
        cont++;
        if(vehicles[id] == k) return cont;
    }

    return -1;
}
