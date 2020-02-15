#include <bits/stdc++.h>
// https://omegaup.com/arena/problem/Distancia-entre-dos-puntos#problems
// Tag(s): Geometría
using namespace std;
#define watch(x) cout << (#x) << " es " << (x) << endl;
#define EPS 1.19209e-07
#define fastIO ios_base::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL);
typedef long long int lli;
typedef long double ld;
typedef vector<int> vi;
typedef vector<long long int> vlli;
typedef vector<double> vd;
lli MAX = 1e9+7;

struct punto {
    ld x, y;
};

int main() {
	fastIO
    punto a, b;
    cin >> a.x >> a.y;
    cin >> b.x >> b.y;
    ld ans = sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
    cout << ans << endl;
	return 0;
}
