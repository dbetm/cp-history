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

int main() {
	fastIO();
    int val = 0;
    int n;
    cin >> n;
    string op;
    while(n--) {
        cin >> op;
        if(op[1] == '+') val++;
        else val--;
    }
    cout << val << endl;
	return 0;
}
