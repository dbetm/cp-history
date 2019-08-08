#include <bits/stdc++.h>
// https://www.hackerrank.com/challenges/kaprekar-numbers/problem
using namespace std;
#define watch(x) cout << (#x) << " es " << (x) << endl;
#define EPS 1.19209e-07
#define fastIO() ios_base::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL);
typedef long long int lli;
typedef vector<int> vi;
typedef vector<long long int> vlli;
typedef vector<double> vd;
lli MAX = 1e9+7;

bool isModifiedKaprekarNumber(int n) {
    bool ans = true;
    int d = to_string(n).size();
    int64_t num = (int64_t)n*(int64_t)n;
    string num_str = to_string(num);

    string r = "0";
    string l = "0";
    int lim = num_str.size();

    for (int i = lim-d; i < lim; i++) {
        r += num_str[i];
    }

    for (int j = 0; j <= lim-1-d; j++) {
        l += num_str[j];
    }

    int64_t a = stoi(r);
    int64_t b = stoi(l);

    // cout << n << ": " << b << " + " << a << endl;

    if((a + b) != n) ans = false;

    return ans;
}

int main() {
	fastIO();
    int p, q;
    cin >> p >> q;
    vector <int> ans;

    for (int i = p; i <= q; i++) {
        if(isModifiedKaprekarNumber(i)) ans.push_back(i);
    }

    if(ans.size() == 0) cout << "INVALID RANGE" << endl;
    else {
        for (size_t i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }

	return 0;
}
