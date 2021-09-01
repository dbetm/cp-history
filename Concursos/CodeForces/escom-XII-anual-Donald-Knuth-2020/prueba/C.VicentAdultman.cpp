#include <bits/stdc++.h>
//
// Tag(s):
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
    vector<int> arr(4);
    int x;
    for (size_t i = 0; i < 4; i++) {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    cin >> x;

    if(x <= arr[3] + arr[2] + arr[1]) {
        cout << "WAW" << endl;
    }
    else cout << "AWW" << endl;

	return 0;
}
