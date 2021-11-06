#include <bits/stdc++.h>
//
// Tag(s):
using namespace std;
#define watch(x) cout << (#x) << " es " << (x) << endl;
#define EPS 1.19209e-07
#define fastIO ios_base::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL);

int main() {
    fastIO
    double kx1, ky1, ox1, oy1;
    double kx2, ky2, ox2, oy2;
    double ans = 0.0;
    cout << setprecision(6) << fixed;

    cin >> kx1 >> ky1 >> ox1 >> oy1 >> kx2 >> ky2 >> ox2 >> oy2;

    // inicial-inicial
    double distance = sqrt(pow(kx1 - ox1, 2) + pow(ky1 - oy1, 2));
    if(distance > ans) ans = distance;
    /*
    watch(distance)
    // inicial-final
    distance = sqrt(pow(kx1 - ox2, 2) + pow(ky1 - oy2, 2));
    if(distance > ans) ans = distance;
    watch(distance)
    // final-inicial
    distance = sqrt(pow(kx2 - ox1, 2) + pow(ky2 - oy1, 2));
    if(distance > ans) ans = distance;
    watch(distance)
    */
    // final-final
    distance = sqrt(pow(kx2 - ox2, 2) + pow(ky2 - oy2, 2));
    if(distance > ans) ans = distance;

    cout << ans << endl;

	return 0;
}
