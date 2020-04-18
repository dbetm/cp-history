#include <bits/stdc++.h>
//
// Tag(s):
using namespace std;
#define watch(x) cout << (#x) << " es " << (x) << endl;
#define EPS 1.19209e-07
#define fastIO ios_base::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL);
typedef long long int lli;
typedef unsigned long long int ulli;
typedef vector<int> vi;
typedef vector<long long int> vlli;
typedef vector<double> vd;
lli MAX = 1e9+7;

int main() {
    fastIO
    ulli res = 0;
    int n;
    cin >> n;
    ulli arr[n];
    ulli suma = 0;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        suma += arr[i];
    }
    for (int i = 0; i < n; i++) {
        suma -= arr[i];
        res += arr[i] * suma;
    }
    cout << (ulli)res << endl;
	return 0;
}
