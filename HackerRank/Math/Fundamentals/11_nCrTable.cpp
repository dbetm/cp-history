#include <bits/stdc++.h>
// https://www.hackerrank.com/challenges/ncr-table/problem
using namespace std;
#define fastIO() ios_base::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL);
typedef long long int lli;
uint64_t MAX = 1e9 + 7;
vector<lli> table(int64_t n);
vector<lli> nCx(int n, int k);

int main() {
    fastIO();
    int t, n;
    cin >> t;
    while(t--) {
        cin >> n;
        vector <lli> ans = table(n);
        int delta = 2;
        if(n & 1) delta = 1;
        for (int i = 0; i < (int)ans.size(); i++) {
            cout << ans[i] << " ";
        }
        for (int i = ans.size() - delta; i >= 0; i--) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}

vector<lli> table(int64_t n) {
    int64_t k = n/2;
    vector <lli> ans = nCx(n, k);
    return ans;
}

vector<lli> nCx(int n, int k) {
    vector<lli> C(k+1, 0);
    C[0] = 1;

    for (int i = 1; i <= n; i++) {
        for (int j = min(i, k); j > 0; j--) {
            C[j] = (C[j]%MAX + C[j-1]%MAX) % MAX;
        }
    }
    return C;
}
