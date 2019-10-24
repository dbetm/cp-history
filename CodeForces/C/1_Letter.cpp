#include <bits/stdc++.h>
// https://codeforces.com/problemset/problem/180/C
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
	fastIO
    string cadena;
    cin >> cadena;
    int upperCase = 0, lowerCase = 0, ans = 0;

    for (size_t i = 0; i < cadena.size(); i++) {
        if(cadena[i] >= 'A' && cadena[i] <= 'Z') lowerCase++;
    }

    if(lowerCase != 0 && lowerCase != (int)cadena.size()) {
        ans = lowerCase + upperCase;
        for (size_t i = 0; i < cadena.size(); i++) {
            if(cadena[i] >= 'a' && cadena[i] <= 'z') upperCase++;
            else lowerCase--;

            ans = min(ans, lowerCase + upperCase);
        }
    }

    cout << ans << endl;

	return 0;
}
