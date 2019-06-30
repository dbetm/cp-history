#include <bits/stdc++.h>
// https://omegaup.com/arena/problem/Ordenando-cajas#problems
using namespace std;
typedef long long int lli;
typedef vector<int> vi;
typedef vector<long long int> vlli;
typedef vector<double> vd;

#define MAX 5
#define PESO_MAX 250

void _setup() {
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main() {
	_setup();
    vd pesos(MAX);
    double total = 0;
    int n = 5;
    bool error = false;
    while(n--) {
        cin >> pesos[n];
        if(pesos[n] < 0.0001) error = true;
    }

    if(error) cout << "ERROR" << endl;
    else {
        sort(pesos.begin(), pesos.end());

        for (int i = pesos.size()-1; i >= 0; i--) {
            if(total + pesos[i] > PESO_MAX) cout << 0 << endl;
            else cout << pesos[i] << endl;
            total += pesos[i];
        }
    }
	return 0;
}
