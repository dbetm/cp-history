#include <bits/stdc++.h>
// Aceptado
// Tag(s): Implementación, mates
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
    string str_n;
    cin >> str_n;

    if(str_n.size() == 1 or str_n == "10") {
        cout << str_n << endl;
    }
    else {
        bool increment = str_n[1] >= '5';
        if(increment) {
            if(str_n[0] == '9') cout << "10";
            else cout << ++str_n[0];
        }
        else {
            cout << str_n[0];
        }
        for (size_t i = 0; i < str_n.size()-1; i++) {
            cout << 0;
        }
        cout << endl;
    }

	return 0;
}
