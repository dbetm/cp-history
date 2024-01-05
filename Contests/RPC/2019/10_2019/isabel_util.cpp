#include <bits/stdc++.h>
//
using namespace std;
#define watch(x) cout << (#x) << " es " << (x) << endl;
#define EPS 1.19209e-07
#define fastIO() ios_base::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL);
typedef long long int lli;
typedef vector<int> vi;
typedef vector<long long int> vlli;
typedef vector<double> vd;
lli MAX = 1e9+7;
int dic[10] = {6,2,5,5,4,5,6,4,7,6};
uint64_t calc(int n);
uint64_t contDigs(uint64_t i);
int res[130];
uint64_t piv = 1;

int main() {
	fastIO();
    for (int i = 1; i <= 128; i++) {
        piv = calc(i);
        cout << i << ": " << (uint64_t)piv << endl;
    }
	return 0;
}

uint64_t calc(int n) {
    uint64_t ans, i = piv;
    do {
        ans = contDigs(i);
        //watch(ans)
        i++;
    } while(ans <= n);
    return (--i);
}

uint64_t contDigs(uint64_t i) {
    uint64_t suma = 0;
    int dig;
    while(i > 0) {
        dig = i % 10;
        suma += dic[dig];
        i /= 10;
    }
    //watch(suma)
    return suma;
}
