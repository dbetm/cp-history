#include <bits/stdc++.h>
// WA
// Tags: DP
using namespace std;
#define watch(x) cout << (#x) << " es " << (x) << endl;
#define EPS 1.19209e-07
#define fastIO ios_base::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL);
#define INF 1000
typedef long long int lli;
typedef vector<int> vi;
typedef vector<long long int> vlli;
typedef vector<double> vd;
lli MAX = 1e9+7;


int min(int a, int b, int c) {
    return min(a, min(b, c));
}

int main() {
	fastIO
    int n, ans = 0;
    cin >> n;
    int arr[n];
    bool logg[n+1][2];
    memset(logg, false, sizeof(logg));

    int tabla[n][3];

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i < n; i++) {
        if(arr[i] == 0) { // solo puede descansar
            // contest
            tabla[i][1] = INF;
            // gym
            tabla[i][2] = INF;
            // descansar
            tabla[i][0] = ans + 1;
        }
        else if(arr[i] == 1) { // puede concursar o descansar
            // contest
            if(logg[i][0]) tabla[i][1] = INF;
            else {
                logg[i+1][0] = true;
                tabla[i][1] = ans;
            }
            // gym
            tabla[i][2] = INF;

            // descansar
            tabla[i][0] = ans + 1;
        }
        else if(arr[i] == 2) { // puede gym o descansar
            // contest
            tabla[i][1] = INF;
            // gym
            if(logg[i][1]) tabla[i][2] = INF;
            else {
                logg[i+1][1] = true;
                tabla[i][2] = ans;
            }
            // descansar
            tabla[i][0] = ans + 1;
        }
        else { // puede gym, concursar o descansar
            // contest
            if(logg[i][0]) tabla[i][1] = INF;
            else {
                logg[i+1][0] = true;
                tabla[i][1] = ans;
            }
            // gym
            if(logg[i][1]) tabla[i][2] = INF;
            else {
                logg[i+1][1] = true;
                tabla[i][2] = ans;
            }
            // descansar
            tabla[i][0] = ans + 1;
        }
        ans = min(tabla[i][0], tabla[i][1], tabla[i][2]);
    }

    cout << ans << endl;

	return 0;
}
