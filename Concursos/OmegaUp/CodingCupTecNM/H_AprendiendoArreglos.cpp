#include <bits/stdc++.h>
//
using namespace std;
#define watch(x) cout << (#x) << " es " << (x) << endl;
#define EPS 1.19209e-07
#define fastIO ios_base::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL);
typedef long long int lli;
typedef vector<int> vi;
typedef vector<long long int> vlli;
typedef vector<double> vd;
lli MAX = 1e9+7;

int main() {
	fastIO
    int tabla[1001];
    memset(tabla, -1, sizeof(tabla));
    int n, num, ans = 0;
    int a, b;
    cin >> n;
    while(n--) {
        cin >> num;
        tabla[num]++;
    }
    cin >> a >> b;
    for (int i = a; i <= b; i++) {
        if(tabla[i] != -1) ans += tabla[i] + 1;
    }

    cout << ans << endl;
	return 0;
}
