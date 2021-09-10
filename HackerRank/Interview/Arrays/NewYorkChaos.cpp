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

void minimumBribes(vector<int> &q) {
    int n = q.size()-1;
    int positions[n+1];
    int ans = 0;

    for (int i = 1; i <= n; ++i) positions[i] = i;

    for (int i = 1; i <= n; ++i) {
        //watch(q[i])
        //watch(positions[q[i]])
        int delta = i - positions[q[i]];
        if(delta < -2) {
            cout << "Too chaotic" << endl;
            return;
        }
        else if(delta == -1) {
            ans += 1;
            positions[q[i]]--;
            positions[q[i]-1]++;
        }
        else if(delta == -2) {
            ans += 2;
            positions[q[i]] -= 2;
            positions[q[i]-1]++;
            positions[q[i]-2]++;
        }
    }

    cout << ans << endl;
}

int main() {
    fastIO
    int t, n;
    cin >> t;

    while(t--) {
        cin >> n;
        vi q(n+1);

        for (int i = 1; i <= n; i++) {
            cin >> q[i];
        }

        minimumBribes(q);
    }

	return 0;
}
