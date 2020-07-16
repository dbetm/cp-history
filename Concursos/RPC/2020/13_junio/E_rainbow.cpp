#include <bits/stdc++.h>
// AC
// Tag(s): Implementation, number theory
using namespace std;
#define watch(x) cout << (#x) << " es " << (x) << endl;
#define EPS 1.19209e-07
#define fastIO ios_base::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL);
typedef long long int lli;
typedef vector<int> vi;
typedef vector<long long int> vlli;
typedef vector<double> vd;
lli MAX = 1e9+7;

int main() {
    int cont[26] = {0};
    const int prime = 11092019;
    string s;
    cin >> s;

    int len = s.size();

    for (int i = 0; i < len; i++) {
        int index = (int)(s[i]-97);
        //watch(index)
        cont[index]++;
    }
    lli res = 1;
    for (int i = 0; i < 26; i++) {
        res = (res*(cont[i]+1)) % prime;
    }

    cout << (lli)res << endl;

	return 0;
}
