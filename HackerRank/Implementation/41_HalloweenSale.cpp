#include <bits/stdc++.h>
// https://www.hackerrank.com/challenges/halloween-sale/problem
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
    int price, discount, uMbral, myMoney, cont = 0;
    cin >> price >> discount >> uMbral >> myMoney;

    while((myMoney-price) >= 0) {
        //watch(price)
        myMoney -= price;
        cont++;
        if(price > uMbral) {
            price -= discount;
            if(price <= uMbral) price = uMbral;
        }
    }
    cout << cont << endl;
	return 0;
}
