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

int main() {
	fastIO();
    int a1, p1, r1, p2;
    double pu1, pu2;
    cin >> a1 >> p1;
    cin >> r1 >> p2;
    pu1 = (double)a1 / (double)p1;
    pu2 = (M_PI * (r1*r1)) / p2;
    if(pu1 > pu2) cout << "Slice of pizza" << endl;
    else cout << "Whole pizza" << endl;
	return 0;
}
