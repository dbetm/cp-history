#include <bits/stdc++.h>
//
using namespace std;
#define watch(x) cout << (#x) << " es " << (x) << endl;
#define EPS 1.19209e-07
#define fastIO() ios_base::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL);
typedef long long int lli;
typedef vector<int> vi;
typedef vector<long long int> vlli;
typedef vector<double> vd;
typedef vector<pair<int, int>> vpi;
lli MAX = 1e9+7;

int main() {
	fastIO();
    int n, s;
    cin >> s >> n;
    vpi datos(n);
    pair<int, int> dragonChars;
    while(n--) {
        cin >> dragonChars.first >> dragonChars.second;
        datos.push_back(dragonChars);
    }
    sort(datos.begin(), datos.end());
    bool flag = true;
    for (size_t i = 0; i < datos.size(); i++) {
        if(datos[i].first >= s) {
            flag = false;
            break;
        }
        s += datos[i].second;
    }
    cout << ((flag) ? "YES" : "NO") << endl;

	return 0;
}
