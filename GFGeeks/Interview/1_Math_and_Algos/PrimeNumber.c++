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
lli MAX = 1e9+7;
bool divisionPorTentativa(lli n);

int main() {
	fastIO();
    int t;
    int64_t n;
    cin >> t;
    while(t--) {
        cin >> n;
        if(n == 1) cout << "No" << endl;
        else if(divisionPorTentativa(n)) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
	return 0;
}

bool divisionPorTentativa(lli n) {
    bool ans = true;
    for (int i = 2; i <= sqrt(n); i++) {
        if(n % i == 0) {
            ans = false;
            break;
        }
    }
    return ans;
}
