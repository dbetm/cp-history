#include <bits/stdc++.h>
// https://codeforces.com/problemset/problem/579/A
// Tag(s): bitmask
using namespace std;
#define watch(x) cout << (#x) << " es " << (x) << endl;
#define EPS 1.19209e-07
#define fastIO ios_base::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL);
typedef long long int lli;
typedef vector<int> vi;
typedef vector<long long int> vlli;
typedef vector<double> vd;
lli MAX = 1e9+7;

inline int popcount(int x){
    int count = 0;
    __asm__ volatile("POPCNT %1, %0;"
        :"=r"(count)
        :"r"(x)
        :
    );
    return count;
}

int main() {
    fastIO
    int x;
    cin >> x;
    cout << (popcount(x)) << endl;
	return 0;
}
