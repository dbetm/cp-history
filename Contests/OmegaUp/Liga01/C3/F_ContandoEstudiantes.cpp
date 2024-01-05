#include <bits/stdc++.h>
//
// Tag(s):
using namespace std;
#define watch(x) cout << (#x) << " es " << (x) << endl;
#define EPS 1.19209e-07
#define fastIO ios_base::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL);
typedef long long int lli;
typedef vector<int> vi;
typedef vector<long long int> vlli;
typedef vector<double> vd;
lli MAX = 1e9+7;

map<int, lli> edades;
map<int, lli> queries;

int main() {
    fastIO
    lli m, p, x;
    cin >> m;
    map<int, lli>::iterator itr;

    while(m--) {
        cin >> p >> x;
        if(p == 1) {
            itr = edades.find(x);
            if(itr == edades.end()) {
                edades[x] = 1;
            }
            else {
                edades[x]++;
            }
        }
        else {
            map<int, lli>::iterator itr;
            int cont = 0;
            for (itr = edades.begin(); itr != edades.end(); itr++) {
                if(itr->first > x) break;
                cont += itr->second;
            }
            cout << cont << endl;
        }
    }

	return 0;
}
