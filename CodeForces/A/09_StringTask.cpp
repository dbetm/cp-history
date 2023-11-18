#include <bits/stdc++.h>
// https://codeforces.com/contest/118/problem/A
using namespace std;
#define watch(x) cout << (#x) << " es " << (x) << endl;
#define EPS 1.19209e-07
#define fastIO() ios_base::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL);
typedef long long int lli;
typedef vector<int> vi;
typedef vector<long long int> vlli;
typedef vector<double> vd;

int main() {
	fastIO();
    char c;
    while(cin >> c) {
        c = tolower(c);
        if(c != 'a' && c != 'e' && c != 'i' && c != 'o' && c != 'u' && c != 'y') {
            cout << "." << (char)tolower(c);
        }
    }
    cout << endl;
	return 0;
}
