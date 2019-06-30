#include <bits/stdc++.h>
// https://omegaup.com/arena/problem/MCD---Primos#problems
using namespace std;
typedef long long int lli;
typedef vector<int> vi;
typedef vector<long long int> vlli;
typedef vector<double> vd;

void _setup();
void mostrarPrimos(int n);

int main() {
	_setup();
    int a, b;
    cin >> a >> b;
    cout << __gcd(a, b) << endl;
    mostrarPrimos(max(a, b));
	return 0;
}

void _setup() {
	ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);
}

void mostrarPrimos(int n) {
    // Criba
    int A[n+1] = {0};
    A[0] = A[1] = 1;
    for (int i = 2; i <= sqrt(n); i++) {
        if(A[i] == 0) {
            for (int j = i; j <= (n / i); j++) {
                A[i*j] = 1;
            }
        }
    }
    int i = 0;
    while(i <= n) {
        if(A[i] == 0) cout << i << " ";
        i++;
    }
    cout << endl;
}
