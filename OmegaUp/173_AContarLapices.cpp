#include <bits/stdc++.h>
//
using namespace std;
typedef long long int lli;
typedef vector<int> vi;
typedef vector<long long int> vlli;
typedef vector<double> vd;

void _setup();

int main() {
	_setup();
    int n, k, num, cont = 0;
    cin >> n >> k;
    while(n--) {
        cin >> num;
        if(num == k) cont++;
    }
    cout << cont << endl;
	return 0;
}

void _setup() {
	ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);
}
