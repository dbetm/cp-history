#include <bits/stdc++.h>
// https://omegaup.com/arena/problem/Binario-a-Decimal--ASINUS#problems
using namespace std;
typedef long long int lli;
typedef vector<int> vi;
typedef vector<long long int> vlli;
typedef vector<double> vd;

void _setup();
vi toBinary(int);

int main() {
	_setup();
    int n;
    cin >> n;
    if(n < 0 || n > 500) cout << "Error" << endl;
    else {
        vi ans = toBinary(n);
        for (int i = ans.size()-1; i >= 0; i--) {
            cout << ans[i] << endl;
        }
    }
	return 0;
}

void _setup() {
	ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);
}

vi toBinary(int n) {
    vi ans;
    while(n > 0) {
        ans.push_back(n % 2);
        n /= 2;
    }
    return ans;
}
