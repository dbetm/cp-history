#include <bits/stdc++.h>
// TLE
using namespace std;
#define watch(x) cout << (#x) << " es " << (x) << endl;
#define EPS 1.19209e-07
#define fastIO() ios_base::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL);
typedef long long int lli;
typedef vector<int> vi;
typedef vector<long long int> vlli;
typedef vector<double> vd;
lli MAX = 1e9+7;

int main() {
	fastIO();
    lli n;
	cin >> n;
	lli arr[n];
	lli lis[n];

	for (int i = 0; i < n; i++) cin >> arr[i];

	// Verificar la condición aj*2 >= ai, donde j < i
	lis[0] = 1;
	for (int i = 1; i < n; i++) {
	   lis[i] = 1;
	   for (int j = 0; j < i; j++) {
		   if(arr[i] < arr[j]*2 && lis[i] < lis[j] + 1) lis[i] = lis[j] + 1;
	   }
   }

	cout << (*max_element(lis, lis+n)) << endl;

	return 0;
}
