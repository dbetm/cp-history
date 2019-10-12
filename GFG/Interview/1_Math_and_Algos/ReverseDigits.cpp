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

int main() {
	fastIO();
    int t;
    string n;
    cin >> t;
    bool flag;
    while(t--) {
        cin >> n;
        flag = true;
        for (int i = n.size()-1; i >= 0; i--) {
            if(flag && n[i] == '0') continue;
            else flag = false;
            cout << n[i];
        }
        cout << endl;
    }

	return 0;
}
