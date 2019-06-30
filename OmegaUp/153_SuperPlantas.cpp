#include <bits/stdc++.h>
// https://omegaup.com/arena/problem/Super-Plantas-ASINUS#problems
using namespace std;
typedef long long int lli;
typedef vector<int> vi;
typedef vector<long long int> vlli;
typedef vector<double> vd;

void _setup() {
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
}

int main() {
    _setup();
	int numHojas;
    double total = 0, oxigeno, areaHoja;
    vd oxigenoPorHoja;
    bool error = false;

    cin >> numHojas;
    if(numHojas == 0) cout << "ERROR" << endl;
    else {
        while(numHojas--) {
            cin >> areaHoja;
            if(abs(areaHoja-0) < 0.0001) error = true;
            oxigeno = areaHoja * 0.5;
            oxigenoPorHoja.push_back(oxigeno);
            total += oxigeno;
        }
        if(error) cout << "ERROR" << endl;
        else if(total <= 3.0) cout << "COMUN" << endl;
        else {
            for (int i = 0; i < (int)oxigenoPorHoja.size(); i++) {
                cout << oxigenoPorHoja[i] << endl;
            }
            cout << total << endl;
        }
    }
	return 0;
}
