#include <bits/stdc++.h>
// https://codeforces.com/contest/996/problem/A
using namespace std;
#define watch(x) cout << (#x) << " es " << (x) << endl;
#define EPS 1.19209e-07
#define fastIO() ios_base::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL);
typedef long long int lli;
typedef long int li;
typedef vector<int> vi;
typedef vector<long long int> vlli;
typedef vector<double> vd;
lli MAX = 1e9+7;

li arr[] = {1, 5, 10, 20, 100};

int main() {
	fastIO();
    li n;
    cin >> n;
    li cont = 0;

    for (int i = 4; i >= 0; i--) {
        li num = (n / arr[i]);
        n -= (num * arr[i]);
        cont += num;
        if(n == 0) break;
    }

    cout << cont << endl;

	return 0;
}
