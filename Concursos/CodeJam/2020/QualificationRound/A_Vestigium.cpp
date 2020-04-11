#include <bits/stdc++.h>
// Test 1/1 Accepted
// Tag(s): Implementation
using namespace std;
#define watch(x) cout << (#x) << " es " << (x) << endl;
#define EPS 1.19209e-07
#define fastIO ios_base::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL);
typedef long long int lli;
typedef vector<int> vi;
typedef vector<long long int> vlli;
typedef vector<double> vd;
lli MAX = 1e9+7;
void compute(int n, lli &trace, int &r, int &c);

int main() {
    fastIO
    int t, n, cont = 1, r, c;
    lli trace;
    // input test cases
    cin >> t;
    while(t--) {
        // input dim of matrix
        cin >> n;
        compute(n, trace, r, c);
        cout << "Case #" << (cont++) << ": " << trace << " " << r << " " << c << endl;
    }
	return 0;
}

void compute(int n, lli &trace, int &r, int &c) {
    trace = 0;
    r = 0;
    c = 0;
    int m[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> m[i][j];
        }
    }
    // Sum elements of main diagonal and check repeats in rows and cols.
    for (int i = 0; i < n; i++) {
        set<int> col, row;
        for (int j = 0; j < n; j++) {
            if(i == j) trace += m[i][j];
            row.insert(m[i][j]);
            col.insert(m[j][i]);
        }
        if(int(row.size()) < n) r++;
        if(int(col.size()) < n) c++;
    }
}
