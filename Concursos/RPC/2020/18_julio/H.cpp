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
    int n;
    int d = 0, t = 41, tmp;

    cin >> n;
    int temps[n];

    for (int i = 0; i < n; i++) {
        cin >> temps[i];
    }

    for (int i = 0; i < n-2; i++) {

        tmp = max(temps[i], temps[i+2]);
        if(tmp < t) {
            d = i+1;
            t = tmp;
        }
    }

    cout << d << " " << t << endl;
	return 0;
}
