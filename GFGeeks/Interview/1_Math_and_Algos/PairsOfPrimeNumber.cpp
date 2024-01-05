#include <bits/stdc++.h>
// https://practice.geeksforgeeks.org/problems/pairs-of-prime-number/0/
/*
1 ≤ T ≤ 50
4 ≤ N ≤ 400
*/
using namespace std;
#define watch(x) cout << (#x) << " es " << (x) << endl;
#define EPS 1.19209e-07
#define fastIO ios_base::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL);
typedef long long int lli;
typedef vector<int> vi;
typedef vector<long long int> vlli;
typedef vector<double> vd;
lli MAX = 1e9+7;
bool arr[201];
vi primos;

void printPrimeFactors(int n);
void generarCriba();

int main() {
	fastIO
    arr[0] = arr[1] = 1;
    generarCriba();
    int t, n;
    cin >> t;
    while(t--) {
        cin >> n;
        printPrimeFactors(n);
    }

	return 0;
}

void printPrimeFactors(int n) {
    int tam = primos.size();
    for (int i = 0; i < tam; i++) {
        for (int j = 0; j < tam; j++) {
            if(primos[i]*primos[j] <= n) {
                cout << primos[i] << " " << primos[j] << " ";
            }
            else break;
        }
    }
    cout << endl;
}

void generarCriba() {
    int n = 201;
    for (int i = 2; i < sqrt(n); i++) {
        if(arr[i] == 0) {
            for (int j = i; j <= (n / i); j++) {
                arr[i*j] = 1;
            }
        }
    }

    for (int i = 2; i <= 200; i++) {
        if(!arr[i]) primos.push_back(i);
    }

    // for (size_t i = 0; i < primos.size(); i++) {
    //     cout << primos[i] << endl;
    // }
    // cout << "-----------" << endl;
}
