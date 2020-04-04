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

int main() {
    fastIO
    int n, m;
    cin >> n >> m;
    string camino;
    cin >> camino;
    int i = 0;
    int ans = 0;

    while(1) {
        if(i + m < n) { // puede saltar
            bool salvado = false;
            for (int j = i+m; j >= i; j--) {
                if(camino[j] == '1') {
                    i = j;
                    salvado = true;
                    break;
                }
            }
            if(!salvado) {
                ans = -1;
                break;
            }
        }
        else {
            if(i < n-1) ans++;
            break;
        }
        ans++;
    }

    cout << ans << endl;

	return 0;
}
