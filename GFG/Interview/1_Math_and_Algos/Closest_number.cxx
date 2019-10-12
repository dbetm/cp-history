#include <bits/stdc++.h>
// https://practice.geeksforgeeks.org/problems/closest-number/0/
using namespace std;
#define watch(x) cout << (#x) << " es " << (x) << endl;
#define EPS 1.19209e-07
#define fastIO() ios_base::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL);
typedef long long int lli;
typedef vector<int> vi;
typedef vector<long long int> vlli;
typedef vector<double> vd;
lli MAX = 1e9+7;

int getClosestNumber(int n, int m) {
    int ans;
    int ans1 = n;
    int ans2 = n;
    int x = abs(m);

    do {
        if(abs(ans1) % x == 0 && abs(ans2) % x == 0) {
            ans = max(abs(ans1), abs(ans2));
            if(abs(ans1) > abs(ans2)) ans = ans1;
            else ans = ans2;
            break;
        }
        else if(abs(ans1) % x == 0) {
            ans = ans1;
            break;
        }
        else if(abs(ans2) % x == 0) {
            ans = ans2;
            break;
        }
        ans1++;
        ans2--;
    } while(true);

    return ans;
}

int main() {
	fastIO();
    int t, n, m;
    cin >> t;
    while(t--) {
        cin >> n >> m;
        cout << getClosestNumber(n, m) << endl;
    }
 	return 0;
}
