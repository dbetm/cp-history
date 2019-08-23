#include <bits/stdc++.h>
// https://omegaup.com/arena/problem/boredx100#problems
using namespace std;
#define watch(x) cout << (#x) << " es " << (x) << endl;
typedef long long int lli;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, num;
    cin >> n;
    map<lli, lli> datos;

    for (int i = 0; i < n; i++) {
        cin >> num;
        try {
            datos[num]++;
        }
        catch(...) {
            pair<lli, lli> par;
            par.first = num;
            par.second = 1;
            datos.insert(par);
        }
    }

    map<lli, lli>::iterator itr;
    int j;
    for (itr = datos.begin(); itr != datos.end(); ++itr) {
        j = itr->second;
        //watch(j)
        while(j--) {
            cout << itr->first << " ";
        }
    }
    cout << endl;

    return 0;
}
