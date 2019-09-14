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
lli MAX = 1e9+7;

int64_t superDigit(uint64_t p);

int main() {
	fastIO();
    uint64_t p;
    char c;
    int k;
    uint64_t tabla[10] = {0};
    do {
        cin >> noskipws >> c;
        if((int)c == 32) break;
        tabla[(int)c - 48]++;
    } while(true);

    cin >> k;

    for (int i = 0; i < 10; i++) {
        p += tabla[i] * i * k;
    }
    cout << superDigit(p) << endl;

	return 0;
}

int64_t superDigit(uint64_t p) {
    if(p < 10) return p;
    int64_t nP = 0;
    while(p > 0) {
        nP += p % 10;
        p /= 10;
    }
    return superDigit(nP);
}
