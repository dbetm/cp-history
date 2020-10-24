#include <bits/stdc++.h>
// WA
// Tag(s): Greedy
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
    int n, k, x, len, minDistance, totalDistance = INT_MAX;
    pair<int, int> currentTile, nextTile;
    cin >> n >> k;
    vector<pair<int, int>> tiles[k+1];

    for(int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> x;
            tiles[x].push_back({i+1, j+1});
        }
    }

    for (int i = 1; i <= k; i++) {
        if(tiles[i].size() == 0) {
            cout << -1 << endl;
            return 0;
        }
    }
    len = tiles[1].size();

    for (int i = 0; i < len; i++) {
        currentTile = tiles[1][i];
        int distance = 0;
        for(int j = 2; j <= k; j++) {
            int len2 = tiles[j].size();
            minDistance = INT_MAX;
            for (int k = 0; k < len2; k++) {
                int aux = abs(tiles[j][k].first - currentTile.first);
                aux += abs(tiles[j][k].second - currentTile.second);
                if(minDistance > aux) {
                    nextTile = tiles[j][k];
                    minDistance = aux;
                }
            }
            distance += minDistance;
            currentTile = nextTile;
        }
        totalDistance = min(totalDistance, distance);
    }

    cout << totalDistance << endl;

	return 0;
}
