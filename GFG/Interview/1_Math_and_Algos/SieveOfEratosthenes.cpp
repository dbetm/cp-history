#include <bits/stdc++.h>
// https://practice.geeksforgeeks.org/problems/sieve-of-eratosthenes/0/
// Tag(s): math, number theory
using namespace std;
#define watch(x) cout << (#x) << " es " << (x) << endl;
#define EPS 1.19209e-07
#define fastIO ios_base::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL);
typedef long long int lli;
typedef vector<int> vi;
typedef vector<long long int> vlli;
typedef vector<double> vd;
lli MAX = 1e9+7;
const lli N = 10000;
bool criba[N+1];

void generarCriba();
void imprimir(int n);

int main() {
    fastIO
    generarCriba();
    int t, n;
    cin >> t;
    while(t--) {
        cin >> n;
        imprimir(n);
    }
	return 0;
}

void generarCriba() {
    criba[0] = true;
    criba[1] = true;
    for (int i = 2; i <= sqrt(N); i++) {
        if(criba[i] == false) {
            for (int j = i; j <= (N / i); j++) {
                criba[i*j] = true;
            }
        }
    }
}

void imprimir(int n) {
    for (int i = 2; i <= n; i++) {
        if(criba[i] == false) {
            cout << i << " ";
        }
    }
    cout << endl;
}
