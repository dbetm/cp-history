#include <bits/stdc++.h>
// https://omegaup.com/arena/problem/Numero-Romanos#problems
using namespace std;
typedef long long int lli;
typedef vector<int> vi;
typedef vector<long long int> vlli;
typedef vector<double> vd;

vector<pair<string, int>> simbolos;
void iniciarSimbolos();
void _setup() {
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main() {
	_setup();
    int n;
    cin >> n;
    if(n < 1 || n > 3555) cout << "ERROR" << endl;
    else {
        iniciarSimbolos();
        for (int i = 0; i < (int)simbolos.size(); i++) {
            int it = n / simbolos[i].second;
            //cout << it << endl;
            if(n != 0) {
                for (int j = 0; j < it; j++) {
                    cout << simbolos[i].first;
                }
                n %= simbolos[i].second;
            }
            else break;
        }
        cout << endl;
    }
	return 0;
}

void iniciarSimbolos() {
    simbolos.push_back(make_pair("M", 1000));
    simbolos.push_back(make_pair("CM", 900));
    simbolos.push_back(make_pair("D", 500));
    simbolos.push_back(make_pair("CD", 400));
    simbolos.push_back(make_pair("C", 100));
    simbolos.push_back(make_pair("XC", 90));
    simbolos.push_back(make_pair("L", 50));
    simbolos.push_back(make_pair("XL", 40));
    simbolos.push_back(make_pair("X", 10));
    simbolos.push_back(make_pair("IX", 9));
    simbolos.push_back(make_pair("V", 5));
    simbolos.push_back(make_pair("IV", 4));
    simbolos.push_back(make_pair("I", 1));
}
