#include <bits/stdc++.h>
//
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

int main() {
	fastIO
    string linea;
    int64_t ans = 0;

    while(cin >> linea) {
        if(linea[0] == '|') {
            ans += (int)linea.size() * 42;
        }
        else {
            bool flag = false;
            string strNumber = "";
            lli number;
            int cont = 0;
            for(char c : linea) {
                if(flag && c != '-') cont++;
                if(c == ',') {
                    flag = true;
                }
                else if(c >= '0' && c <= '9') {
                    strNumber += c;
                }
            }
            stringstream aux(strNumber);
            aux >> number;
            if(cont == 0) ans += number;
            else ans += number * cont;
        }
    }

    int delta = ans % 10;
    delta = (delta > 0) ? 10 - delta : 0;
    ans += delta;

    cout << (int64_t)(ans) << ",-" << endl;
	return 0;
}
