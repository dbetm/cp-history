#include <bits/stdc++.h>
// https://omegaup.com/arena/problem/Las-hormigas-ASINUS#problems
using namespace std;
typedef long long int lli;
typedef vector<int> vi;
typedef vector<long long int> vlli;
typedef vector<double> vd;

void _setup() {
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main() {
	_setup();
    int sotano = 0, piso1 = 0, piso2 = 0, n;
    bool error = false;
    char c;
    cin >> n;
    if(n <= 0) {
        cout << "ERROR" << endl;
    }
    else {
        while(n--) {
            cin >> c;
            if(c == '3') sotano++;
            else if(c == '2') piso2++;
            else if(c == '1') piso1++;
            else {
                error = true;
                break;
            }
        }
        if(error) cout << "ERROR" << endl;
        else {
            cout << sotano << endl;
            cout << piso1 << endl;
            cout << piso2 << endl;
        }
    }
	return 0;
}
